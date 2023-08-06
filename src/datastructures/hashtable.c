#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

HashTable *ht_init(U32 datasize) {
  // allocate hash table
  HashTable *ht = malloc(sizeof(HashTable));

  // allocate the hash table with 100000 pointers
  ht->entries = malloc(sizeof(Entry *) * TABLE_SIZE);
  ht->capacity = TABLE_SIZE;
  ht->size = 0;
  ht->datasize = datasize;

  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->entries[i] = NULL;
  }

  return ht;
}

U32 hash(const char *key) {
  U64 hash = 0ULL;

  // sdbm hash function
  int c;
  while ((c = *key++)) {
    hash = c + (hash << 6) + (hash << 16) - hash;
  }

  return hash % TABLE_SIZE;
}

Entry *ht_individualEntry(HashTable *ht, const char *key, const void *val) {
  Entry *entry = malloc(sizeof(Entry));

  entry->key = malloc(strlen(key));
  entry->val = malloc(ht->datasize);

  strcpy(entry->key, key);
  memcpy(entry->val, val, ht->datasize);
  entry->next = NULL;

  printf("Val: %d, Entry val: %d\n", *(int *)val, *(int *)entry->val);

  return entry;
}

enum HashTableCodes ht_add(HashTable *ht, const char *key, const void *val) {
  U32 hashed = hash(key);

  if (ht->entries[hashed] == NULL) {
    ht->entries[hashed] = ht_individualEntry(ht, key, val);
    ht->size += 1;
    return HT_STATUS_OK;
  }

  Entry *entry = ht_individualEntry(ht, key, val);

  Entry *next = ht->entries[hashed];
  while (next) {
    if (strcmp(key, next->key) == 0) {
      printf("Hash already exists\n");
      return HASH_EXISTS;
    }

    if (!next->next) {
      next->next = entry;
      break;
    }
    next = next->next;
  }
  ht->size += 1;
  return HT_STATUS_OK;
}

enum HashTableCodes ht_check(HashTable *ht, const char *key) {
  U32 hashed = hash(key);

  Entry *entry = ht->entries[hashed];

  if (!entry)
    return HASH_DOES_NOT_EXIST;

  while (entry) {
    if (strcmp(entry->key, key) == 0)
      return HASH_EXISTS;

    entry = entry->next;
  }
  return HASH_DOES_NOT_EXIST;
}

Entry *ht_getEntry(HashTable *ht, const char *key) {
  U32 hashed = hash(key);

  Entry *entry = ht->entries[hashed];
  if (!entry)
    return NULL;

  while (strcmp(key, entry->key) != 0) {
    entry = entry->next;
  }
  return entry;
}

// Not 100% sure this works
static void free_entries(Entry *entry) {
  if (entry->next) {
    free_entries(entry->next);
  }

  free(entry->val);
  free(entry->key);
  free(entry);
}

void ht_clear(HashTable *ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (ht->entries[i] == NULL)
      continue;

    // go through every part of the malloced memory to clean
    Entry *entry = ht->entries[i];
    free_entries(entry);
  }
}

// TODO: Implement delete safely so there are no hanging pointers on delete
enum HashTableCodes ht_delete(HashTable *ht, const char *key) {
  U32 hashed = hash(key);
  int found = 0;

  Entry *entry = ht->entries[hashed];
  Entry *previous = NULL;

  while (!found) {
    if (strcmp(key, entry->key) == 0) {
      found = 1;
    } else if (entry->next == NULL) {
      break;
    } else {
      previous = entry;
      entry = entry->next;
    }
  }

  if (!found) {
    printf("No has not deleted");
    return HASH_NOT_DELETED;
  }

  // last entry in linked list
  Entry *next = entry->next;
  free(entry->key);
  free(entry->val);
  free(entry);

  if (previous && next) {
    previous->next = next;
  }

  return HT_STATUS_OK;
}
