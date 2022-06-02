#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stackCDT* stackADT;


stackADT initStack(size_t elemSize);
void freeStack(stackADT stack);


//agrega un elem al tope de la pila
void push(stackADT stack, void* elem);

//elimina elem en la tope de la pilla y te lo devulve
void * pop(stackADT stack);

//te devulve el elemnto del tope de la pila
void * peek(stackADT stack);

//devulve true si la pila esta vacia
int stackIsEmpty(stackADT stack);

//devulve la cantidad de elem en la pila
int getStackSize(stackADT stack);

//iterador
void stackToBegin(stackADT stack);

int stackHasNext(const stackADT stack);

void* stackNext(stackADT stack) ;