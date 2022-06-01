#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stackCDT* stackADT;


stackADT initStack(size_t elemSize);
void deleteStack(stackADT stack);
void push(stackADT stack, void* elem);
void * pop(stackADT stack);
int getStackSize(stackADT stack);