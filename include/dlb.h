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
void add(dlb* d, const char* key);


/**
 * @brief Search for prefix in dlb (Note: if `prefix` is
 * a key, then `prefix` isn't valid)
 * 
 * @param d dlb to search through
 * @param prefix to search for
 * @return `int` returns 1 if `prefix` is a prefix to a key, otherwise returns 0
 */
int is_prefix(dlb* d, char* prefix);

#endif 
