#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaGeneric.h"
#include "stackADTv2.h"
#include "../variables/variable.h"



typedef struct scopeCDT* scope;


scope initScope();

int addDefinition(scope scope, enum type type, char* variableName);

int addAssigId(scope scope, int id, enum type type, void* value);

void* getValueId(scope scope, int id);

void* getValueName(scope scope, char* name);

void newScope(scope stack);

void endScope(scope stack);