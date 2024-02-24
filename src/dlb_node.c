#include <stdlib.h>
#include "dlb_node.h"

dlb_node* new_dlb_node(char let)
{
    dlb_node* new_node;
    if (new_node = malloc(sizeof(dlb_node)) == NULL)
        return NULL;
    new_node->let = let;
    new_node->freq = 0;
    new_node->right = NULL;
    new_node->down = NULL;
    return new_node;
}