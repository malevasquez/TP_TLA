#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include "../support/utils.h"
#include <string.h>

/* Marcadores de inicio y fin */

void start_program();
void end_program();

/* Signos de operacion */

void plusValue();
void minusValue();
void multiplyValue();
void divideValue();

/* Condicionales y Ciclos */

void ifValue();
void thenValue();
void elseValue();
void endIfValue();
void doStatementValue();
void whileValue();

/* Signos de comparacion */

void greaterValue();
void lowerValue();
void equalValue();
void notEqualValue();

/* Operadores logicos */

void andValue();
void orValue();
void notValue();

/* Valores de verdad */

void trueValue();
void falseValue();

/* Funciones */

void printNum(int value);
void printStr(char * str);

void printToChords(char *notes);

void toChord(const char* note1, const char* note2, const char* note3);
void toNotes(char* chord);

void isNote(char *note);
void isChord(char *value);

void concatNotes(char * note1, char * note2, char * note3);

/* Simbolos */

void openParValue();
void closeParValue();
void delimiterValue();

/* Data Format */

void getIntegerValue(int value);
void getStringValue(char* string);

#endif
