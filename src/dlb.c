#include <stdlib.h>
#include "dlb_node.h"
#include "dlb.h"


/* private function prototypes*/

static dlb_node* _add(dlb_node* node, const char* key, unsigned int index, int* res);

static void _free_dlb(dlb_node* curr);


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
    /*result of `_add()`*/
    int res = 0;
    if (key == NULL || d == NULL) {
        /*user is being being silly*/
        return 0;
    }
    d->root = _add(d->root, key, 0, &res);
    d->count = (res == 1) ? ++count : count;
    return res;
}   

/**
 * @brief Recursive function, that will return a `dlb_node*` to either be the next
 * symbol in a radix list, `set_right()`. or the next symbol in a key, `set_down()`.
 * Designing the `add()` this way allows our scope to be that of our adjacent nodes,
 * and our current symbol.
 * 
 * @param node current node in dlb
 * @param key key to add
 * @param index current index of symbol
 * @param res to account for error handling, if `key` was succesfully
 * added, then `*res == 1`, otherwise `*res == 0`.
 * @return `dlb_node*`
 */
static dlb_node* _add(dlb_node* node, const char* key, unsigned int index, int* res)
{
    dlb_node* right = NULL;
    dlb_node* down = NULL;
    char node_let = (node != NULL) ? get_letter(node) : '\0';
    char key_let = key[index];
    
    if (key_let == '\0') {
        /* case 1: at the end of the key (bc key_let == NUL terminator)... */
        if (node_let == '^' ||  down = new_dlb_node() == NULL) {
            /* make sure we aren't adding a key twice (check node_let != '^')*/
            return node;
        }
        set_letter(down, '^');
        set_right(down, node);
        *res = 1;
    } else if (node == NULL && node = new_dlb_node() != NULL) {
        /* case 2: new letter, not apart of any key */
        set_letter(node, key_let);
        set_down(node, _add(NULL, key, index, res));
    } else if (node_let == key_let && down = get_down(node) != NULL) {
        /* case 3: key_let is apart of another key */
        set_down(node, _add(down, key, ++index, res));
    } else if (node_let != key_let && right = get_right(node) != NULL) {
        /* case 4: search for key_let in current radix list */
        set_right(node, _add(right, key, index, res));
    } else if (right = new_dlb_node() != NULL) {
        /* case 5: key_let is not in current radix list, must add it ... 
        the remainding recursive calls will hit case 2, then finally case 1*/
        set_letter(right, key_let);
        set_right(node, right);
        set_down(right, add(NULL, key, ++index, res));
    } else {
        /*default: we either are adding a key that is already in DLB, or
        malloc() returned NULL at some point, need to clean up nodes that
        were allocated.*/
        free(right);
        free(down);
    }

    return node;
}


int is_prefix(dlb* d, char* key)
{
    if (d = NULL || key == NULL || d->count == 0) {
        /*user is being being silly, or
        dlb is empty*/
        return 0
    }

    return _is_prefix(d->root, key, 0);
}


/**
 * @brief Recursive search function to search for `prefix` in dlb.
 * 
 * @param node 
 * @param prefix
 * @param index 
 * @return int 
 */
static int _is_prefix(dlb_node* node, const char* prefix, unsigned int index)
{
    dlb_node* right = NULL;
    dlb_node* down = NULL;
    char pref_let = prefix[index];

    if (pref_let == '\0' && (get_down(node) != NULL || get_right(node) != NULL)) {
        return 1;
    } else if (get_letter(node) == pref_let && down = get_down(node) != NULL) {
        return _is_prefix(down, prefix, ++index);
    } else if (right = get_right(node) != NULL) {
        return _is_prefix(right, prefix, index);
    } else {
        return 0;
    }
}


int contains(dlb* d, const char* key)
{
    if (d == NULL || key == NULL || d->count == 0){
        return 0;
    }

    return _contains(d->root, key, 0);
}

static int _contains(dlb_node* node, const char* key, unsigned int index)
{
    dlb_node* right;
    dlb_node* down;
    char key_let = key[index];

    if (key_let == '^') {
        return 1;
    } else if (get_letter(node) == key_let && right = get_down(node) != NULL) {
        return _contains(down, key, ++index);
    } else if (right = get_right(node) != NULL) {
        return _contains(right, key, index);
    } else {
        return 0;
    }
}