#include "dlb_node.h"

#ifndef DLB
#define DLB

typedef struct _dlb{
    dlb_node* root;             // Root node
    unsigned long key_count;    // Number of keys in dlb
    unsigned long char_count;   // Number of characters (This distinguishes between keys)
    dlb_node* curr_key;         // Current by-character search node 
} dlb;

#endif

#ifndef DLB_FUNCS
#define DLB_FUNCS


/**
 * @brief Create a new De La Brandais Trie (dlb)
 * 
 * @return dlb* 
 */
dlb* new_dlb();


/**
 * @brief Free allocated dlb
 * 
 * @param d dlb to free
 */
void free_dlb(dlb* d);


/**
 * @brief Add new key to dlb
 * 
 * @param d dlb to add key to
 * @param key being added
 * @return `int` return 1 if added to d, otherwise 0.
 */
int add(dlb* d, const char* key);


/**
 * @brief Check if the dlb contains the given key
 * 
 * @param d dlb to search
 * @param key searching for
 * @return `int` 1 if the key is present in d, otherwise 0
*/
int contains(dlb* d, const char* key);


/**
 * @brief Search for prefix in dlb (Note: if `prefix` is
 * a key and not a prefix to any other key, then 
 * `prefix` isn't valid)
 * 
 * @param d dlb to search through
 * @param prefix to search for
 * @return `int` returns 1 if `prefix` is a prefix to a key, otherwise returns 0
 */
int is_prefix(dlb* d, char* prefix);

/**
 * @brief Search for a word one character at a time
 * 
 * @param next Next character to search for
 * @return int value indicating result for current by-character search:
 * 
 * -1: not a valid word or prefix
 *  0: valid prefix, but not a valid word
 *  1: valid word, but not a valid prefix to any other words
 *  2: both valid word and a valid prefix to other words
 */
int search_by_char(char next);

/**
 * Reset the state of the current by-character search
*/
void reset_by_char(dlb* d);

/**
 * @brief Suggest up to `n` key from the dictionary based on the current by-character search.
 * 
 * X Idea 1: everytime the user chooses a word, it will move up one place in the current radix it was chosen
 *      - con: can't differentiate between keys that have been chosen more the number of keys in the current radix
 *              (e.g. radix := k1, k2, k3 and we have chosen k1 four times and chosen k2 two times., once we choose 
 *               k2 for a third time, it will be the shown as the most frequent.)
 * 
 * @param buf array to add keys to
 * @param n number of keys to suggest at most
 */
void suggest(dlb* d, char* buf[], int n);

/**
 * @brief List all of the keys currently stored in the dlb.
 * 
 * @param buf array to add keys to
 */
void traverse(dlb* d, char* buf[]);


#endif 
