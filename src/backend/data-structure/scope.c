#include "scope.h"

#define SIZEOF(arr) strlen(arr) * sizeof(char *)

typedef struct scopeCDT {
  int netxId;
  stackADT stack;
} scopeCDT;

// privadas:
int getID(scopeADT scope);
elem *scopeSearch(stackADT stack, void *elem2,
                  int (*cmp)(void *elem1, void *elem2));
int scopeContains(stackADT stack, void *elem2,
                  int (*cmp)(void *elem1, void *elem2));
int cmpName(void *elem1, void *value);
int cmpId(void *elem1, void *value);
int deleteElem(void *elem1);
int deleteList(void *elem1);
elem *creatElem(int id, enum type type, const char *elemName);
int addAssign(elem **elem1, enum type type, void *value);

// funciones:
scopeADT newScope() {

  // creó un stack de listADT
  stackADT stack = newStack(deleteList);
  if (stack == NULL)
    return NULL;

  // creo un lista de elem
  listADT list = newList(deleteElem);
  if (list == NULL)
    return NULL;

  // la guardo en el stack
  if (push(stack, list) == -1)
    return NULL;

  // creo un nuevo scope
  scopeADT scope = malloc(sizeof(scopeCDT));
  if (scope == NULL)
    return NULL;

  scope->stack = stack;
  scope->netxId = 0;

  return scope;
}

// devuelve el ID de la variable y solo la inserta si no existe
// si hubo un erro devuelve -1
int addDefinition(scopeADT scope, enum type type, char *variableName) {

  listADT list = (listADT)peek(scope->stack);

  // busaco en el scope actual si hay una variable con el mismo nombre
  if (elemBelongs(list, variableName, cmpName))
    return -1;

  // creo el id de la variable
  int elemId = getID(scope);

  elem *newElem = creatElem(elemId, type, variableName);

  // lo guardo en la lista
  insert(list, newElem);

  return elemId;
}

void createSubScope(scopeADT scope) {
  // creo un lista de elem
  listADT list = newList(deleteElem);
  // la guardo en el stack
  push(scope->stack, list);
}

void endSubScope(scopeADT scope) {
  // borro la ultima lista
  if (stackSize(scope->stack) <= 1)
    return;
  pop(scope->stack);
}

// devuleve -1 si hubo un error
int addAssignById(scopeADT scope, int id, enum type type, void *value) {
  elem *elem = getElemById(scope, id);
  if (elem == NULL)
    return -1;

  return addAssign(&elem, type, value);
}

// devuleve -1 si hubo un error
int addAssignByName(scopeADT scope, char *name, enum type type, void *value) {
  elem *elem = getElemByName(scope, name);
  if (elem == NULL)
    return -1;

  return addAssign(&elem, type, value);
}

int addAssign(elem **elem1, enum type type, void *value) {
  elem *auxElem = *elem1;
  size_t valueSize;

  if (auxElem->type != type)
    return -1;

  if (type == _STRING)
    valueSize = SIZEOF(value);
  else
    valueSize = sizeof(int);

  if(value != NULL){
    auxElem->value = malloc(valueSize);
    memcpy(auxElem->value, value, valueSize);
  }
  
  return 0;
}

// devulve el elemnt si lo encontro sino NULL
elem *getElemById(scopeADT scope, int id) {
  return scopeSearch(scope->stack, &id, cmpId);
}

// devulve el elemnt si lo encontro sino NULL
elem *getElemByName(scopeADT scope, char *name) {
  return scopeSearch(scope->stack, name, cmpName);
}

void freeScope(scopeADT scope) {
  freeStack(scope->stack);
  free(scope);
}

////////////////////////////////////////////////////////////////////////////////
// funcines privadas
/////////////////////////////////////////////////////////////////////////////

// busca en todas las lista de la pila si elemento tiene el valor value
elem *scopeSearch(stackADT stack, void *value,int (*cmp)(void *elem, void *value)) {
  elem *toReturn = NULL;

  stackToBegin(stack);
  while (stackHasNext(stack)) {
    listADT currentList = (listADT)stackNext(stack);
    toReturn = (elem *)getElem(currentList, value, cmp);
    if (toReturn != NULL)
      return toReturn;
  }

  return toReturn;
}

int scopeContains(stackADT stack, void *value,
                  int (*cmp)(void *elem, void *value)) {
  elem *toReturn = scopeSearch(stack, value, cmp);
  if (toReturn == NULL)
    return 0;
  return 1;
}

// funciones de comparacion
int cmpName(void *elem1, void *value) {
  elem *aux = (elem *)elem1;
  char *name = (char *)value;
  if (strcmp(aux->name, name) == 0) {
    return 0;
  }
  return 1;
}

int cmpId(void *elem1, void *value) {
  elem *aux = (elem *)elem1;
  int *id = (int *)value;
  if (aux->id == (*id)) {
    return 0;
  }
  return 1;
}

int getID(scopeADT scope) {
  int toReturn = scope->netxId;
  scope->netxId++;
  return toReturn;
}

elem *creatElem(int id, enum type type, const char *elemName) {

  elem *toReturn = malloc(sizeof(elem));

  toReturn->id = id;
  toReturn->type = type;

  toReturn->value = NULL;
  // toReturn->value = malloc(getTypeSize(type));
  // toReturn->value = value;

  toReturn->name = malloc(SIZEOF(elemName));
  strcpy(toReturn->name, elemName);

  return toReturn;
}

int deleteElem(void *elem1) {
  elem *aux = (elem *)elem1;
  free(aux->value);
  free(aux->name);
  free(elem1);
  return 0;
}

int deleteList(void *elem1) { 
  freeList((listADT)elem1);
  return 0;
}
