#ifndef SCOPE_H
#define SCOPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaGeneric.h"
#include "stackADTv2.h"
#include "../variables/variable.h"

typedef struct elem {
    int id;
    enum type type;
    char *name;
    void *value;
} elem;

typedef struct scopeCDT* scopeADT;

scopeADT newScope();

//devuelve el ID de la variable y solo la inserta si no existe
//si hubo un erro devuelve -1
int addDefinition(scopeADT scope, enum type type, char *variableName);


//debe inicilizar un pnt con malloc y guardar el valor.
int addAssignById(scopeADT scope, int id, enum type type, void *value);

int addAssignByName(scopeADT scope, char *name, enum type type, void *value);

elem* getElemById(scopeADT scope, int id);

elem* getElemByName(scopeADT scope, char *name);

void freeScope(scopeADT scope);

//crea un nuevo scope
void createSubScope(scopeADT scope);

//elimina el ultimo scope
void endSubScope(scopeADT scope);

#endif