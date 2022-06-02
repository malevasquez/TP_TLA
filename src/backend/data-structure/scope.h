#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaGeneric.h"
#include "stackADTv2.h"
#include "../variables/variable.h"



typedef struct scopeCDT* scopeADT;

//inicializa el scope
scopeADT initScope();

//devuelve el ID de la variable y solo la inserta si no existe
//si hubo un erro devuelve -1
int addDefinition(scopeADT scope, enum type type, char* variableName);

int addAssigId(scopeADT scope, int id, enum type type, void* value);

void* getValueId(scopeADT scope, int id);

void* getValueName(scopeADT scope, char* name);

//OJO
void freeScope(scopeADT scope);

//crea un nuevo scope
void newScope(scopeADT stack);

//elimina el ultimo scope
void endScope(scopeADT stack);