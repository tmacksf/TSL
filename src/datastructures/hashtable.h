#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../base.h"
#include "vector.h"
#include <string.h>

/* A hash table implementation which uses a string key and anything for the
 * value
 */
#define TABLE_SIZE 100000

typedef struct Entry {
  char *key;
  void *val;
  struct Entry *next;
} Entry;

typedef struct HashTable {
  Entry **entries; /* array of pointers to enteies */
  u32 datasize;
  u32 size;
  u32 capacity;
} HashTable;

enum HashTableCodes {
  HT_STATUS_OK = 0,
  HASH_DOES_NOT_EXIST,
  HASH_EXISTS,
  HASH_NOT_DELETED,
};

/* Creates a hash table
 * Params: datasize
 * Returns: Hash table pointer
 */
HashTable *ht_init(u32 datasize);

/* hash function */
u32 hash(const char *key);

/* Creates an individual entry
 * Params: hash table, key, value
 * Returns: entry
 */
Entry *ht_individualEntry(HashTable *ht, const char *key, const void *val);

/* Adds an entry to a hash table
 * Params: hash table, key, value
 * Returns: status code
 */
enum HashTableCodes ht_add(HashTable *ht, const char *key, const void *val);

/* Checks if a key is in the hash table
 * Params: hash table, key
 * Returns: status code
 */
enum HashTableCodes ht_check(HashTable *ht, const char *key);

/* Gets a hash table entry
 * Params: hash table, key
 * Returns hash table entry
 */
Entry *ht_getEntry(HashTable *ht, const char *key);

/* Clears a hash tbale
 * Params: hash table
 * Returns: void
 */
void ht_clear(HashTable *ht);

/* Deletes an entry
 * Params: hash table, key
 * Returns: status code
 */
enum HashTableCodes ht_delete(HashTable *ht, const char *key);

/*Gets the keys of a hash table
 * Params: hash table
 * Returns: vector of keys
 */
Vector *ht_getKeys(HashTable *ht);

#endif
