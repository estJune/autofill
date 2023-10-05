#include <stdlib.h>
#include "dlb_node.h"

static inline dlb_node* new_dlb_node(char let)
{
    dlb_node* new_node = malloc(sizeof(dlb_node));
    if (!new_node){
        return NULL
    }
    new_node->let = let;
    new_node->right = NULL;
    new_node->down = NULL;
    return new_node;
}

static inline void set_right(dlb_node* node, dlb_node* right)
{
    node->right = right;
}

static inline void set_down(dlb_node* node, dlb_node* down)
{
    node->down = down;
}

static inline dlb_node* get_right(dlb_node* node)
{
    return node->right;
}

static inline dlb_node* get_down(dlb_node* node)
{
    return node->down;
}

static inline char get_letter(dlb_node* node)
{
    return node->let;
}

