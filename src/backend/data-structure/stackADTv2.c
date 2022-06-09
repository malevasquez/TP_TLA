#include "stackADTv2.h"


typedef struct node{
    void * value;
    struct node* next;
}node;

typedef struct stackCDT{
    node* first;
    node* iteradorNext;  //iterador
    int (*elemFree) (void*); //funcion que borra los elemntos
    int size;   //cantidad de elemtos
}stackCDT;


stackADT newStack(int (*elemFree)(void*)){

    stackADT newStack = malloc(sizeof(stackCDT));
    if(newStack == NULL){
        return NULL;
    }
    newStack->first=NULL;
    newStack->elemFree= elemFree;
    newStack->size = 0;

    return newStack;
}

//retorna -1 si hubo erro, sino 0
int push(stackADT stack, void* elem){

    //creo el nuevo nodo
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL)
        return -1;

    newNode->next = stack->first;

    newNode->value = elem;

    stack->first = newNode;

    stack->size ++;

    return 0;
}

void* pop(stackADT stack){

    if(stack->first == NULL){
        return NULL;
    }
    node* auxNode = stack->first;

    if(auxNode->next != NULL){
        stack->first = auxNode->next;
    }

    void* toReturn = auxNode->value;

    free(auxNode);
    stack->size--;

    return toReturn;
}

void * peek(stackADT stack){
    return stack->first->value;
}

int stackSize(stackADT stack){
    return stack->size;
}

int getStackStructSize(){
    return sizeof(stackCDT);
}

int stackIsEmpty(stackADT stack){
    return stack->size == 0;
}


void freeStack(stackADT stack){
    node* current = stack->first;
    node* aux;
    while (current != NULL) {
        aux = current->next;
        stack->elemFree(current->value);
        free(current);
        current = aux;
    }
    free(stack);;
}


//iterador
void stackToBegin(stackADT stack) {
	stack->iteradorNext = stack->first;
}

int stackHasNext(const stackADT stack) {
	return stack->iteradorNext != NULL;
}

void* stackNext(stackADT stack) {
	if (!stackHasNext(stack))
        return NULL;
	void* toReturn = stack->iteradorNext->value;
	stack->iteradorNext = stack->iteradorNext->next;

	return toReturn;
}





