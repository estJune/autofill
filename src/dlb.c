#include <stdlib.h>
#include "dlb_node.h"
#include "dlb.h"



dlb* new_dlb()
{
    dlb* d;
    if ((d = malloc(sizeof(dlb)) == NULL))
        return NULL;
    d->key_count = 0;
    d->char_count = 0;
    d->root = NULL;
    d->curr_key = NULL;
    return d;
}


static void _free_dlb(dlb_node* curr)
{
    dlb_node* down;
    dlb_node* right;
    if ((down = curr->down) != NULL) {
        _free_dlb(down);    
    }
    if ((right = curr->right) != NULL) {
        _free_dlb(right); 
    }
    (void) free(curr); 
    curr = NULL;
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


/**
 * @brief Recursive helper insert function, that will return a `dlb_node*` to either be the next
 * symbol in a radix list, `node->right = ?`. or the next symbol in the key, `node->down = ?`.
 * Designing the insert this way allows our scope to be that of our adjacent nodes,
 * and our current symbol, which makese it easier to handle when `malloc() == NULL`.
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
    char node_let = (node != NULL) ? node->let : '\0';
    char key_let = key[index];
    
    if (key_let == '\0') {
        // case 1: at the end of the key
        if (node_let == '\0' ||  (down = new_dlb_node('\0')) == NULL) {
            /* Make sure we aren't adding a key twice (check node_let != '\0')
            or we run out of memory, `malloc() == NULL`*/
            return node;
        }
        down->right = node;
        *res = 1;
    } else if (node == NULL && (node = new_dlb_node(key_let)) != NULL) {
        /* case 2: new letter, not apart of any key */
        node->down = _add(NULL, key, index, res);
    } else if (node_let == key_let && (down = node->down) != NULL) {
        /* case 3: key_let is apart of another key */
        node->down = _add(down, key, ++index, res);
    } else if (node_let != key_let && (right = node->right) != NULL) {
        /* case 4: search for key_let in current radix list */
        node->right = _add(right, key, index, res);
    } else if (right = new_dlb_node(key_let) != NULL) {
        /* case 5: key_let is not in current radix list, must add it ... 
        the remainding recursive calls will hit case 2, then finally case 1*/
        node->right = right;
        right->down, _add(NULL, key, ++index, res);
    } else {
        /*default: we either are adding a key that is already in DLB, or
        malloc() returned NULL at some point; need to clean up nodes that
        were allocated.*/
        free(right);
        free(down);
    }

    return node;
}


int add(dlb* d, const char* key)
{
    int res = 0;
    // If dlb is empty, or user is being dumb, return 0.
    if (key == NULL || d == NULL) 
        return 0;

    /** 
     * Recursively add key to dlb (Note: `res` is used see if the
     * key was succesfully added or not.
    */
    d->root = _add(d->root, key, 0, &res);
    d->key_count = (res == 1) ? ++d->key_count : d->key_count;
    return res;
}   


/**
 * @brief Iterative helper search function for `is_prefix()` and `contains()`.
 * 
 * @param root the root node
 * @param key key searching for
 * 
 * @return `dlb_node*` if key is present, then return the last node
 * looked at (node that holds some symbol or a terminator). Otherwise,
 * return `NULL`.
*/
static dlb_node* _search_for_key(dlb_node* root, char* key)
{
    int index = 0;                          // Current position in key
    char key_let = key[index];              // Current symbol in key
    dlb_node* curr_node = root;             // Current node
    char node_let = curr_node->let;         // Current node's symbol

    /**
     * If symbols match, then continue to next symbol in key and search
     * next radix. Else if radix is not empty, contiue searching radix
     * for current symbol in key. Otherwise, the key is not in dlb.
    */
    while(key_let != '\0') {                    
        if (node_let == key_let && curr_node->down != NULL) {              
            curr_node = curr_node->down;
            node_let = curr_node->let;
            key_let = key[++index];
        } else if (curr_node->right != NULL){   
            curr_node = curr_node->right;
        } else {                                
            return NULL;
        }
    }

    return curr_node;
}


int is_prefix(dlb* d, char* key)
{
    // If dlb is empty, or user is being dumb, return 0.
    if (d == NULL || key == NULL || d->key_count == 0) 
        return 0;
    
    // Search for key in dlb
    dlb_node* ret_node = _search_for_key(d->root, key);
    if (ret_node == NULL)
        return 0;

    /** 
     * If the returned node's symbol is not a terminator (ret_node != '\0')
     * or the radix is not empty (ret_node->right != NULL), then the key
     * is a prefix. Otherwise, key is not a prefix.
    */
    if (ret_node->let != '\0' || ret_node->right != NULL)
        return 1;

    return 0;
}


int contains(dlb* d, const char* key)
{
    // If dlb is empty, or user is being dumb, return 0.
    if (d == NULL || key == NULL || d->key_count == 0){
        return 0;
    }

    // Search for key in dlb
    dlb_node* ret_node = _search_for_key(d->root, key);
    if (ret_node == NULL)
        return 0;

    /**
     * If the returned node's symbol is a terminator (ret_node->let == '\0'),
     * then the key is in the dlb. Otherwise, key is not in dlb
    */
    if (ret_node->let == '\0')
        return 1;

    return 0;
}


int search_by_char(char next)
{
    return 0;
}


void reset_by_char(dlb* d){}


void suggest(dlb* d, char* buf[], int in)
{

}


void traverse(dlb* d, char* buf[])
{
    /**
     * Option 1: create a buffer with the length of the longest key, use it as a buffer
     * to append keys to a single level buffer that is just single string of keys (e.g
     * buf = [k,e,y,1,\n,k,e,y,2,\n,]). After which we call strtok() to return an array
     * of pointers for convenience. We can preallocate the buffer of size (number of keys
     * x average length string)
     * 
     *  pros: reduce number of malloc() if we did an array of strings (*argv[])
    */
    
}
