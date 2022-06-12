#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include "../support/utils.h"

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


/* Data Format */

void getIntegerValue(int value);
void getStringValue(char* string);

#endif
