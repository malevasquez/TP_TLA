#include "scope.h"

typedef struct elem{
    int id;
    enum type type;
    char* name;
    void * value;
}elem;

typedef struct scopeCDT{
    int netxId;
    stackADT stack;
}scopeCDT ;


int elemSize = sizeof(elem);

//funciones de comparacion
int cmpName(void* elem1, void* elem2){
    //OJO:
    //elem2 es el nombre de la variable
    //elem1 es un elem
    return 1;
}

int cmpId(void* elem1, void* elem2){
    //OJO:
    //elem2 es el nombre de la variable
    //elem1 es un elem
    return 1;
}

//privadas:
int getID(stackADT stack);
void* search(stackADT stack, void* value, int(cmp)(void*, void*));


//funciones:
scopeADT initScope(){

    //creo un stack de listADT
    stackADT stack = initStack(getListSize());

    scopeADT newScope;
    newScope=malloc(sizeof(*newScope));

    newScope->stack = stack;
    newScope->netxId = 0;

    //creo un lista de elem
    listADT list = newList(elemSize, NULL);
    //la guardo en el stack
    push(stack, list);

    return newScope;
}



//devuelve el ID de la variable y solo la inserta si no existe
//si hubo un erro devuelve -1
int addDefinition(scopeADT scope, enum type type, char* variableName){
    
    //busco si ya fue definido la variable
    if(search(scope, variableName, cmpName) != NULL){
        return -1;
    }
    
    //devulve la lista del ultimo scope
    scopeADT stack = scope->stack;
    listADT list = peek(stack);
    if(list == NULL){
        return -1;
    }

    //creo el id de la variable
    int elemId = getID(scope);

    //creo el elemt
    elem newElem;
    newElem.id = elemId;
    newElem.type = type;
    newElem.name = calloc(sizeof(variableName), sizeof(char));
    strcpy(newElem.name, variableName);
    newElem.value = NULL;

    //lo guardo en la lista
    insert(list, &newElem);

    return elemId;
}

void newScope(scopeADT scope){
    //creo un lista de elem
    listADT list = newList(elemSize, NULL);
    //la guardo en el stack
    push(scope->stack, list);
}

void endScope(scopeADT scope){
    //borro la ultima lista
    pop(scope->stack);
}


//TODO no se si funciona
//devuleve -1 si hubo un error
int addAssigId(scopeADT scope, int id, enum type type, void* value){
    elem* elem = getElemById(scope, id);
    if(elem == NULL)
        return -1;    
    memcpy(elem->value, value, type);
    return 0;
}

//TODO no se si funciona
//devuleve -1 si hubo un error
int addAssigName(scopeADT scope, char* name, enum type type, void* value){
    elem* elem = getElemByName(scope, name);
    if(elem == NULL)
        return -1;    
    memcpy(elem->value, value, type);
    return 0;
}


//devulve el elemnt si lo encontro sino NULL
void* getElemById(scopeADT scope, int id){
    elem* elem = search(scope, &id, cmpName);
    return elem->value;
}


//devulve el elemnt si lo encontro sino NULL
void* getElemByName(scopeADT scope, char* name){
    elem* elem = search(scope, name, cmpName);
    return elem->value;
}

void freeScope(scopeADT scope){
     //reinicio el iterator del stack
    stackToBegin(scope->stack);

    while( stackHasNext(scope->stack)){
        listADT currentList = stackNext(scope->stack);
        //creo que falta
        freeList(currentList);
    }

    freeStack(scope->stack);
    free(scope);
}

////////////////////////////////////////////////////////////////////////////////
//funcines privadas
/////////////////////////////////////////////////////////////////////////////

//busca en todas las lista de la pila si elemnto tiene el valor value
void* search(scopeADT scope, void* value, int(cmp)(void*, void*)){
    
    elem* toReturn = NULL;
    
    //reinicio el iterator del stack
    stackToBegin(scope->stack);

    while( stackHasNext(scope->stack) && toReturn == NULL){
        listADT currentList = stackNext(scope->stack);
        //busco en esta lista si esta erl
        toReturn = (elem*) getElem(currentList, value, cmp);
    }
    return toReturn;
}

int getID(scopeADT stack){
    int toReturn = stack->netxId;
    stack->netxId ++;
    return toReturn;
}