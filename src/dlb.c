#include <stdlib.h>
#include "dlb_node.h"
#include "dlb.h"


dlb* new_dlb()
{
    dlb* d;
    if (d = malloc(sizeof(dlb) == NULL))
        return NULL;
    d->count = 0;
    d->root = NULL;
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


int add(dlb* d, const char* key)
{
    int res = 0;
    if (key == NULL || d == NULL) 
        return ERRINIT;
    d->root = _add(d->root, key, 0, &res);
    return res;
}   


static dlb_node* _add(dlb_node* node, const char* key, unsigned int index, int* res)
{
    dlb_node* right = NULL;
    dlb_node* down = NULL;
    char node_let = get_letter(node);
    char key_let = key[index];

    if (key_let == '\0' node != NULL && get_letter(node) != '^') {
        return node;
    } else if (key_let == '\0' && down = new_dlb_node() != NULL) {
        set_letter(down, '^');
        set_right(down, node);
        *res = 1;
    } else if (node == NULL && node = new_dlb_node() != NULL) {
        set_letter(node, key_let);
        set_down(node, _add(NULL, key, index, res));
    } else if (node_let == key_let && down = get_down(node) != NULL) {
        set_down(node, _add(down, key, ++index, res));
    } else if (node_let != key_let && right = get_right(node) != NULL) {
        set_right(node, _add(right, key, index, res));
    } else if (right = new_dlb_node() != NULL && down = _add(NULL, key, ++index, res)) {
        set_letter(right, key_let);
        set_right(node, right);
        set_down(right, down);
    } else {
        free_dlb_node(right);
        free_dlb_node(down);
    }

    return node;
}


extern int is_prefix(dlb* d, char* key)
{
    if (d = NULL || key == NULL || d->count == 0)
        return ERRINIT;

    return _is_prefix(d->root, key, 0);
}


static int _is_prefix(dlb_node* node, const char* key, unsigned int index)
{
    dlb_node* right = NULL;
    dlb_node* down = NULL;
    char key_let = key[index];

    if (key_let == '^' && (get_down(node) != NULL || get_right(node) != NULL)) {
        return 1;
    } else if (get_letter(node) == key_let && down = get_down(node) != NULL) {
        return _is_prefix(down, key, ++index, len);
    } else if (right = get_right(node) != NULL) {
        return _is_prefix(right, key, index, len);
    } else {
        return 0;
    }
}
