#include "stackADTv2.h"


typedef struct node{
    void * elem;
    void * next;
}node;

typedef struct stackCDT{
    node* first;
    node* iteradorNext;  //iterador

    size_t elemSize; //en bytes
    int stackSize;   //cantidad de elemtos
}stackCDT;

//funciones privadas:
static void deleteNode(node* n);


stackADT initStack(size_t elemSize){

    stackADT newStack;

    newStack=malloc(sizeof(*newStack));
    newStack->elemSize=elemSize;
    newStack->first=NULL;
    newStack->stackSize = 0;

    return newStack;
}

void freeStack(stackADT stack){

    deleteNode(stack->first);
    free(stack);
}

static void deleteNode(node* n){

    if(n == NULL)
        return;

    deleteNode(n->next);

    free(n->elem);
    free(n);
}


void push(stackADT stack, void* elem){

    //creo el nuevo nodo 
    node* newNode = malloc(sizeof(*newNode));

    //creeo el elem en el nodo
    newNode->elem = malloc(sizeof(stack->elemSize));
    memcpy(newNode->elem, elem, stack->elemSize);
    newNode->next = NULL;

    if(stack->first != NULL){
        newNode->next = stack->first;
    }
    stack->first = newNode;

    //agrego uno al size del stack
    stack->stackSize ++;
}


//TODO revisar el 
void * pop(stackADT stack){
    if(stack->stackSize = 0){
        return NULL;
    }
    //guardo el elem a retornar
    void* toReturn = malloc(sizeof(stack->elemSize));
    memcpy(toReturn, stack->first->elem, stack->elemSize);

    //guardo el nuevo primer nodo
    node* newFirst;
    if(stack->stackSize = 1)
        newFirst = NULL;
    else
        newFirst = stack->first->next;
    
    
    //borro el nodeo que era primero
    free(stack->first->elem);
    free(stack->first);
    stack->stackSize --;

    stack->first = newFirst;
    
    return toReturn;
}

void * peek(stackADT stack){
    return stack->first->elem;
}

int getStackSize(stackADT stack){
    return stack->stackSize;
}

int stackIsEmpty(stackADT stack){
    return stack->stackSize == 0;
}


//iterador
void toBegin(stackADT stack) {
	stack->iteradorNext = stack->first;
}

int hasNext(const stackADT stack) {
	return stack->iteradorNext != NULL;
}

void* next(stackADT stack) {
	if (hasNext(stack))
		toBegin(stack);
	void* toReturn = stack->iteradorNext->elem;
	stack->iteradorNext = stack->iteradorNext->next;

	return toReturn;
}



