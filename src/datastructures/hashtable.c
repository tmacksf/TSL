#include "hashtable.h"

HashTable *ht_init(U32 datasize) {
  /* allocate hash table */
  HashTable *ht = malloc(sizeof(HashTable));

  /* allocate the hash table with 100000 pointers */
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

  /* sdbm hash function */
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
      /* free allocated memory */
      free(entry->key);
      free(entry->val);
      free(entry);
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

  /* BUG! Sometimes the entry will be null but it won't break -> crashes on
  strcmp
  TODO: Fix the BUG
  */
  Entry *entry = ht->entries[hashed];
  if (!entry)
    return NULL;

  while (strcmp(key, entry->key) != 0) {
    entry = entry->next;
  }
  return entry;
}

/* Not 100% sure this works */
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

    /* go through every part of the malloced memory to clean */
    Entry *entry = ht->entries[i];
    free_entries(entry);
  }
  ht->size = 0;
}

/* TODO: Implement delete safely so there are no hanging pointers on delete */
/* Need to copy hanging entry into array if array entry is deleted and is
pointing to collision entry
*
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

  last entry in linked list
  Entry *next = entry->next;
  free(entry->key);
  free(entry->val);
  free(entry);

  if (previous && next) {
    previous->next = next;
  }
  ht->size -= 1;

  return HT_STATUS_OK;
}
*/

Vector *ht_getKeys(HashTable *ht) {
  /* A vector of pointers. Each pointer points to the key */
  Vector *vector = vector_init(sizeof(char *));

  for (int i = 0; i < TABLE_SIZE; i++) {
    if (ht->entries[i] == NULL)
      continue;

    /* TODO: Test this to make sure its working properly */
    vector_add(vector, &ht->entries[i]->key);
    Entry *next = ht->entries[i]->next;
    while (next) {
      vector_add(vector, next->key);
      next = next->next;
    }
  }

  /* The output of this will need to be broken down as a char** */
  return vector;
}
