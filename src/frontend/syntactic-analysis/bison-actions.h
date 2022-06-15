#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../../backend/variables/variable.h"
#include "../../backend/domain-specific/notes.h"
#include "../../backend/domain-specific/functions.h"
#include "../../backend/data-structure/scope.h"
#include <stdio.h>
#include <string.h>
#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"


/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

// Programa.
int ProgramGrammarAction(char* value);
int EndProgramGrammarAction(char* value);

// Expresión.
int AdditionExpressionGrammarAction(const int leftValue, const int rightValue);
int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue);
int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue);
int DivisionExpressionGrammarAction(const int leftValue, const int rightValue);
int FactorExpressionGrammarAction(const int value);

// Factores.
int ExpressionFactorGrammarAction(const int value);
int ConstantFactorGrammarAction(const int value);

// Signos de Operacion
int PlusGrammarAction(char * value);
int MinusGrammarAction(char * value);
int MultiplyGrammarAction(char * value);
int DivideGrammarAction(char * value);

// Condicionales y Ciclos
int IfGrammarAction(char * value);
int ThenGrammarAction(char * value);
int ElseGrammarAction(char * value);
int EndIfGrammarAction(char * value);
int DoGrammarAction(char * value);
int WhileGrammarAction(char * value);

// Comparacion
int GreaterGrammarAction(char * value);
int LowerGrammarAction(char * value);
int EqualGrammarAction(char * value);
int NotEqualGrammarAction(char * value);

// Operadores logicos
int AndGrammarAction(char * value);
int OrGrammarAction(char * value);
int NotGrammarAction(char * value);

// Valores de verdad
int TrueGrammarAction(char * value);
int FalseGrammarAction(char * value);

// Funciones
int PrintIntegerGrammarAction(int value);
int PrintStringGrammarAction(char * value);
int PrintChordGrammarAction(char * value);
int PrintNoteGrammarAction(char * value);

int ToChordGrammarAction(char * func, char* notes);
int ToNotesGrammarAction(char * func, char * chord);

int ConcatNotesGrammarAction(char * func, char * notes);

int PrintToChordsGrammarAction(char * value);

int CreatePartitureGrammarAction(char * input);

// Validaciones
int ValidateIsNoteGrammarAction(char *value);
int ValidateIsChordGrammarAction(char *value);

// Simbolos
int OpenParGrammarAction(char * value);
int CloseParGrammarAction(char * value);
int DelimiterGrammarAction(char * value);

//ASSIGNMENT
int AssignmentNumByIdGrammarAction(int id, enum type type1, int value);
int AssignmentStringByIdGrammarAction(int id, enum type type1, char* value);
int AssignmentNumByNameGrammarAction(char *name, enum type type1, int value);
int AssignmentStringByNameGrammarAction(char *name, enum type type1, char* value);

//DEFINITION
int DefinitionGrammarAction(enum type type1, char *variableName);
int VariableExpressionGrammarAction(char* name);

// DATA TYPES     
int IntegerConstantGrammarAction(const int value);
char* StringValueGrammarAction(char* str);
int NoteValueGrammarAction(char* note);
int ChordValueGrammarAction(char* chord);

#endif
