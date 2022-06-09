#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scope.h"
//#include "logger.h"
#include "variables/variable.h"


int main(int argc, char const *argv[]) {

    scopeADT scope = newScope();

    if(addDefinition(scope, INTEGER, "par") == -1)
        printf("ERROR");

    if(addDefinition(scope, NOTE, "sol1") == -1)
        printf("ERROR");

    if(addDefinition(scope, NOTE, "par") != -1)
        printf("ERROR");

    if(addDefinition(scope, STRING, "nombre") == -1)
        printf("ERROR");

    ///////////////////////////////////////////////////////////////////
    createSubScope(scope);

    if(addDefinition(scope, INTEGER, "par") == -1)
        printf("ERROR");

    createSubScope(scope);

    if(addDefinition(scope, INTEGER, "par") == -1)
        printf("ERROR");

    createSubScope(scope);

    if(addDefinition(scope, INTEGER, "par") == -1)
        printf("ERROR");

    elem* aux = getElemByName(scope, "sol1");
    printf("%d , %d %s" ,aux->id, aux->type, aux->name);

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
