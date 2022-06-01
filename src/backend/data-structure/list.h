#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/* type: 0 es int, 1 es string, 2 es braille */
struct node{
    char * variable_name;
    int type;
    bool is_assigned;
    struct node *next;
};

void add(char *key, int type);
struct node * find(char *variable_name);

#endif