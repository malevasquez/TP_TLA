#include "functions.h"

/* Marcadores de inicio y fin */

void start_program() {
    // FILE *file = fopen("archivoPrueba.c", "w");
    dprintf(FD, "#include <stdio.h> \nint main()  {\n");
    // printf("#include <stdio.h> int main()  {");
    // program_file = file;
}

void end_program() {
    dprintf(FD, "return 0; }\n");
    // printf("return 0;");
    // fclose(program_file);
}

/* Signos de Operacion */

void plusValue() {
    dprintf(FD, " + ");
}

void minusValue() {
    dprintf(FD, " - ");
}

void multiplyValue() {
    dprintf(FD, " * ");
}

void divideValue() {
    dprintf(FD, " / ");
}

/* Condicionales y Ciclos */

void ifValue() {
    dprintf(FD, "if ");
}

void thenValue() {
    dprintf(FD, " {\n");
}

void elseValue() {
    dprintf(FD, "}\n else {\n");
}

void endIfValue() {
    dprintf(FD, "}\n");
}

void doStatementValue() {
    dprintf(FD, "do {\n");
}

void whileValue() {
    dprintf(FD, "} while ");
}

/* Signos de comparacion */

void greaterValue() {
    dprintf(FD, " > ");
}

void lowerValue() {
    dprintf(FD, " < ");
}

void equalValue() {
    dprintf(FD, " == ");
}

void notEqualValue() {
    dprintf(FD, " != ");
}

/* Operadores logicos */

void andValue() {
    dprintf(FD, " && ");
}

void orValue() {
    dprintf(FD, " || ");
}

void notValue() {
    dprintf(FD, "!");
}

/* Valores de verdad */

void trueValue() {
    dprintf(FD, "1");
}

void falseValue() {
    dprintf(FD, "0");
}

/* Funciones */

// TODO: Hacer las funciones

/* Simbolos */

void openParValue() {
    dprintf(FD, "(");
}

void closeParValue() {
    dprintf(FD, ")");
}

void delimiterValue() {
    dprintf(FD, ";");
}

/* Data Format */

void getIntegerValue(int value) {
    dprintf(FD, "%d", value);
}

void getStringValue(char* string) {
    dprintf(FD, "%s", string);
}
