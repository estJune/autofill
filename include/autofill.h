#include "dlb.h"


#ifndef AUTOFILL
#define AUTOFILL

typedef struct _autofill {
    dlb* dictinoary;                // Dictionary DLB for words in the given file
    dlb* user_history;              // User history DLB for words chosen by user 
} autofill;

#endif

#ifndef AUTOFILL_FUNCS
#define AUTOFILL_FUNCS


/**
 * @brief Create new autofill engine. If `user_history` is passed, engine will
 * read contents from file to pre-load the user history DLB. If the user does not
 * want to pre-load a user history DLB, then pass `NULL`. Expected format for files: 
 * `dictionary` -> `word1\\nword2\\nword3\\n` 
 * `user_history` -> `key 1\\nvalue 2\\nstring 3\\n`
 * 
 * @param dictionary string file name containing a set of words for the user
 * to initially choose from
 * @param user_history string file name to read an already existing user history file
*/
autofill* new_autofill_engine(char*, char*);


/**
 * @brief Produce up to 5 suggestions based on the current word the user has
 * entered These suggestions should be pulled first from the user history
 * dictionary then from the initial dictionary. Any words pulled from user
 * history should be ordered by frequency of use. Any words pulled from
 * the initial dictionary will be in the order they were added, shorter words
 * appearing first.
 * 
 * @param a respective autofill structure
 * @param next char the user just entered
 * 
 * @return `char**` list up to five words prefix by cur
 */
char** next_char(autofill*, char);


/**
 * @brief Process the user selecting the current word
 * 
 * @param a respective autofill structure
 * @param curr word chosen by user
*/
void finish_word(autofill*, char*);


/**
 * @brief Save the state of the user history to a file
 * 
 * @param a respective autofill structure
 * @param file_name char* file name to write history state to
*/
void save_user_history(autofill*, char*);

#endif