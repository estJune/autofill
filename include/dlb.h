#include "dlb_node.h"

#ifndef DLB
#define DLB

typedef struct _dlb{
    dlb_node* root;
    unsigned long count;
} dlb;

#endif

#ifndef DLB_FUNCS
#define DLB_FUNCS


/**
 * @brief 
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
 * @brief Search for prefix in dlb (Note: if `prefix` is
 * a key, then `prefix` isn't valid)
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
void reset_by_char();

/**
 * @brief Suggest up to 5 words from the dictionary based on the current by-character search.
 * 
 * @return * char[] List of up to 5 words that are prefixed by the current by-character search. 
 */
*char[] suggest();

/**
 * @brief List all of the words currently stored in the dictionary.
 * 
 * @return * char[] List of all valid words in dictionary.
 */
*char[] traverse();

/**
 * @brief Count the number of words in the dictionary.
 * 
 * @return int, the number of (distinct) words in the dictionary.
 */
int count();

#endif 
