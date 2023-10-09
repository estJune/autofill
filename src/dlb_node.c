#include <stdlib.h>
#include "dlb_node.h"

dlb_node* new_dlb_node()
{
    dlb_node* new_node;
    if (new_node = malloc(sizeof(dlb_node)) == NULL)
        return NULL;
    new_node->let = '\0';
    new_node->right = NULL;
    new_node->down = NULL;
    return new_node;
}

void set_right(dlb_node* node, dlb_node* right)
{
    node->right = right;
}

void set_down(dlb_node* node, dlb_node* down)
{
    node->down = down;
}

void set_letter(dlb_node* node, char let)
{
    node->let = let;
}

dlb_node* get_right(dlb_node* node)
{
    return node->right;
}

dlb_node* get_down(dlb_node* node)
{
    return node->down;
}

char get_letter(dlb_node* node)
{
    return node->let;
}

