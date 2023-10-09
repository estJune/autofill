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

dlb* new_dlb();

void free_dlb(dlb*);

void add(dlb*, const char*);

int is_prefix(dlb* d, char* key);

#endif 
