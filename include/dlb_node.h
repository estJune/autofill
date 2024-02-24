/*
 * @author Derrick Hicks 
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DLBNODE
#define DLBNODE

/**
 * @brief Do we need to have a terminating node ('\0') if keys only
 * have a positive frequency?
 * 
 */
typedef struct _dlb_node{
    char let;                   // Symbol in key
    unsigned long freq;         // Frequency of this prefix/key
    struct _dlb_node* right;    // Next symbol in radix
    struct _dlb_node* down;     // Next radix in key
} dlb_node;

#endif

#ifndef DLB_NODE_FUNCS
#define DLB_NODE_FUNCS

/**
 * @brief Create a new dlb node
*/
dlb_node* new_dlb_node();

#endif