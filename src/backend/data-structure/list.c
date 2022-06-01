#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

struct node *first = NULL;
struct node *current = NULL;


void add(char *key, int type){
   
    struct node *list = (struct node *)malloc(sizeof(struct node));

    int len = strlen(key);
    list->variable_name = (char *)malloc(sizeof(char) * len + 1);
    strcpy((char *)list->variable_name, (char *)key);
    list->type = type;
    list->is_assigned = false;
    
    list->next = first;

    first = list;
}


struct node *find(char *variable_name){

    char * token = strtok(variable_name, " ,)(+-*/=><");
    
    struct node *current = first;

    if (first == NULL){
        return NULL;
    }

    while (strcmp(current->variable_name, token) != 0){
        if (current->next == NULL){
            return NULL;
        } else{
            current = current->next;
        }
    }
    return current;
}