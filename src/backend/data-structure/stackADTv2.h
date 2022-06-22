#ifndef STACKADT_H
#define STACKADT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stackCDT* stackADT;

////////////////////////////////////////////////////////////
//functions
///////////////////////////////////////////////////////////

stackADT newStack(int (*elemFree)(void*));


//agrega un elem al tope de la pila
int push(stackADT stack, void* elem);

//elimina elem en la tope de la pilla y te lo devulve
void * pop(stackADT stack);

//te devulve el elemnto del tope de la pila
void * peek(stackADT stack);


//devulve la cantidad de elem en la pila
int stackSize(stackADT stack);

int getStackStructSize();

//devulve true si la pila esta vacia
int stackIsEmpty(stackADT stack);



void freeStack(stackADT stack);




//iterador
void stackToBegin(stackADT stack);

int stackHasNext(const stackADT stack);

void* stackNext(stackADT stack);


#endif