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

typedef struct _dlb_node{
    char let;
    struct dlb_node* right;
    struct dlb_node* down;
} dlb_node;

#endif

#ifndef DLB_NODE_FUNCS
#define DLB_NODE_FUNCS

dlb_node* new_dlb_node();

int free_dlb_node(dlb_node*)

void set_right(dlb_node*, dlb_node*);

void set_down(dlb_node*, dlb_node*);

void set_letter(dlb_node*, char);

dlb_node* get_right(dlb_node*);

dlb_node* get_down(dlb_node*);

char get_letter(dlb_node*);

#endif

#ifndef DLB_NODE_ERRORS
#define DLB_NODE_ERRORS

enum errors {SUCC = 0, ERMEMLEAK = -1}

#endif