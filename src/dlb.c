#include <stdlib.h>
#include "dlb_node.h"
#include "dlb.h"


dlb* new_dlb()
{
    dlb* d;
    if (d = malloc(sizeof(dlb) == NULL))
        return NULL;
    d->count = 0;
    return d;
}

void free_dlb(dlb* d)
{
    dlb_node* root;
    if(d == NULL)
        return;
    root = d->root;
    if (root == NULL)
        return;
    _free_dlb(root);
    (void) free(d);
    d = NULL;
}

static void _free_dlb(dlb_node* curr)
{
    dlb_node* down, right;
    if (down = get_down(curr) != NULL) {
        _free_dlb(down);    
    }
    if (right = get_right(curr) != NULL) {
        _free_dlb(right); 
    }
    (void) free(curr); 
    curr = NULL;
}


int add(dlb* d, const char* key, unsigned int len)
{
    long ret = 0;
    if (key == NULL || d == NULL) 
        return ERRINIT;
    if (d->root == NULL && d->root = new_dlb_node() == NULL)
        return ERRNOMEM;
    if (d->count == 0) {
        set_letter(d->root, key[0]);
        (void) d->count++;
    }
    if (ret = _add(d->root, key, 0, len) == SUCC)
        (void) d->count++;
    return ret;
}   


static int _add(dlb_node* curr, const char* key, unsigned int index, unsigned int len)
{
    dlb_node* new_node, right, down;
    char new_letter;

    if (index == len) {
        return SUCC;
    } else {
        new_letter = key[index];
    }

    if (get_letter(curr) == new_letter && down = get_down(curr) != NULL) {
        return _add(down, key, ++index, len);
    } else if (get_letter(curr) != new_letter && right = get_right(curr) != NULL) {
        return _add(right, key, index, len);
    }

    if (new_node = new_dlb_node() == NULL) {
        return ERRNOMEM;
    } else {
        set_letter(new_node, new_letter);
    }

    if (right == NULL) {
        set_right(curr, new_node);
        return _add(new_node, key, index, len);
    } else {
        set_down(curr, new_node);
        return _add(new_node, key, ++index, len);
    }
}
