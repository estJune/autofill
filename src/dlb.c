#include <stdlib.h>
#include "dlb_node.h"
#include "dlb.h"


extern dlb* new_dlb()
{
    dlb* d;
    if (d = malloc(sizeof(dlb) == NULL))
        return NULL;
    d->count = 0;
    d->curr_key_len = 0;
    return d;
}

extern void free_dlb(dlb* d)
{
    dlb_node* root;
    if(d == NULL)
        return;
    root = d->root;
    (void) free(d);
    if (root == NULL)
        return;
    _free_dlb(root);
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


extern void add(dlb* d, const char* key, unsigned int length)
{
    if (key == NULL) 
        return;
    if (d == NULL) {
        return;
    }
    d->curr_key_len = length;
    _add(d, key, 0);
}

static void _add(dlb_node* curr, const char* key, int index)
{
    dlb_node* new_node, right, down;
    char new_letter;

    if (get_letter(curr) != key[index] && right = get_right(new_node) != NULL) {
        _add(right, );
    } else if (get_letter(curr) != key[index] && right = get_right(curr)) {
        _add(right, key, index);
    } else if (index == curr_key_length && new_node = new_dlb_node('^') != NULL) {
        set_right(new_node, curr);
        (void) count++;
        return;
    } else if(get_letter(curr) == key[index] && down = get_down(curr)) {
        if (!down) {

        } else{

        }
        _add(down, key, ++index);
    } 
}
