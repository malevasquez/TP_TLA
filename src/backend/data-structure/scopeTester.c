#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scope.h"
//#include "logger.h"
#include "../variables/variable.h"


int main(int argc, char const *argv[]) {

    scopeADT scope = newScope();

    if(addDefinition(scope, INTEGER, "numero1") == -1)
        printf("ERROR: 1 \n");

    if(addDefinition(scope, NOTE, "nota1") == -1)
        printf("ERROR 2 \n");

    if(addDefinition(scope, NOTE, "nota2") != -1)
        printf("ERROR 3 \n");

    if(addDefinition(scope, STRING, "nombre1") == -1)
        printf("ERROR 4  ok \n");


    createSubScope(scope);

    
    if(addDefinition(scope, INTEGER, "numero2") == -1)
        printf("ERROR 5 \n");

    int numId = addDefinition(scope, INTEGER, "numero1");
    if( numId == -1)
        printf("ERROR 6 \n");

    int* num = (int*) malloc(sizeof(int));
    *num = 100; 
    addAssignById(scope, numId, INTEGER, num, sizeof(int));

    elem* aux = getElemByName(scope, "numero1");
    printf("%d %d %d %s  \n" ,aux->id, aux->type, *((int*)aux->value), aux->name);

    if(addDefinition(scope, INTEGER, "numero2") == -1)
        printf("ERROR 7 > ok");

    endSubScope(scope);
    endSubScope(scope);
    endSubScope(scope);
    endSubScope(scope);
    endSubScope(scope);
    endSubScope(scope);

    aux = getElemById(scope, 0);

    freeScope(scope);

  return 0;
}