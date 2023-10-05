/**
 * @file dlb_node.h
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

typedef struct _dlb_node{
    char let;
    struct dlb_node* right;
    struct dlb_node* down;
} dlb_node;

#endif

#ifndef DLBFUNCS
#define DLBFUNCS

static inline dlb_node* new_dlb_node(char);

static inline void set_right(dlb_node*, dlb_node*);

static inline void set_down(dlb_node*, dlb_node*);

static inline dlb_node* get_right(dlb_node*);

static inline dlb_node* get_down(dlb_node*);

static inline char get_letter(dlb_node*);

#endif