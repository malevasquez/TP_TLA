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

//privadas:
int getID(scope stack);



//funciones:
scope initScope(){

    //creo un stack de listADT
    stackADT stack = initStack(getListSize());

    scope newScope;
    newScope=malloc(sizeof(*newScope));

    newScope->stack = stack;
    newScope->netxId = 0;

    //creo un lista de elem
    listADT list = newList(elemSize, NULL);
    //la guardo en el stack
    push(stack, list);

    return newScope;
}


//devuelve el ID de la variable
int addDefinition(scope scope, enum type type, char* variableName){
    
    //TODO falta ver que no se repita el nombre
    stackADT stack = scope->stack;
    listADT list = peek(stack);
    if(list == NULL){
        //TODO: error manejarlo
    }

    int elemId = getID(scope);

    elem newElem;
    newElem.id = elemId;
    newElem.type = type;
    newElem.name = calloc(sizeof(variableName), sizeof(char));
    strcpy(newElem.name, variableName);
    newElem.value = NULL;

    insert(list, &newElem);

    return elemId;
}

int addAssigId(scope scope, int id, enum type type, void* value){
    
}

int addAssigName(scope scope, char* name, enum type type, void* value){
    
}

void* getValueId(scope scope, int id){

}

void* getValueName(scope scope, char* name){

}


void newScope(scope stack){

}

void endScope(scope stack){

}


int getID(scope stack){
    int toReturn = stack->netxId;
    stack->netxId ++;
    return toReturn;
}


