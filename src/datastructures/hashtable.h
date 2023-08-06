#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../base/base.h"
#include "string.h"

// A hash table implementation which uses a string key and anything for the
// value

#define TABLE_SIZE 100000

typedef struct Entry {
  char *key;
  void *val;
  struct Entry *next;
} Entry;

typedef struct HashTable {
  Entry **entries; // array of pointers to enteies
  U32 datasize;
  U32 size;
  U32 capacity;
} HashTable;

enum HashTableCodes {
  HT_STATUS_OK = 0,
  HASH_DOES_NOT_EXIST,
  HASH_EXISTS,
  HASH_NOT_DELETED,
};

// Creates a hash table
HashTable *ht_init(U32 datasize);

// hash function
U32 hash(const char *key);

Entry *ht_individualEntry(HashTable *ht, const char *key, const void *val);

enum HashTableCodes ht_add(HashTable *ht, const char *key, const void *val);

enum HashTableCodes ht_check(HashTable *ht, const char *key);

Entry *ht_getEntry(HashTable *ht, const char *key);

void ht_clear(HashTable *ht);

enum HashTableCodes ht_delete(HashTable *ht, const char *key);

#endif
