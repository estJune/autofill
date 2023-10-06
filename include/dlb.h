#include "dlb_node.h"

#ifndef DLB
#define DLB

typedef struct _dlb{
    dlb_node* root;
    unsigned long count;
} dlb;

#endif

#ifndef DLB_FUNCS
#define DLB_FUNCS

extern dlb_node* new_dlb();

extern void free_dlb(dlb*);

static void _free_dlb(dlb_node*)

extern void add(dlb*, const char*, unsigned int);

static void _add(dlb_node*, const char*, unsigned int, unsigned int)

#endif 

#ifndef DLB_ERRORS
#define DLB_ERRORS

enum dlb_errors {SUCC = 0, ERRNOMEM = 1, ERRINIT}

#endif