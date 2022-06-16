#include "functions.h"

/* Marcadores de inicio y fin */

void start_program() {
    // FILE *file = fopen("archivoPrueba.c", "w");
    dprintf(FD, "#include <stdio.h>\n#include <string.h>\nint main()  {\nchar printChordAuxArray[100];\n");
    // printf("#include <stdio.h> int main()  {");
    // program_file = file;
}

void end_program() {
    dprintf(FD, "return 0; }\n");
    // printf("return 0;");
    // fclose(program_file);
}

/* Signos de Operacion */

void plusValue()    {
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

void printNum(int value) {
    dprintf(FD, "printf(\"%%d\", %d)", value);
}

void printStr(char * str) {
    dprintf(FD, "printf(%s)", str);
}

void toChord(const char* note1, const char* note2, const char* note3) {
    dprintf(FD, "notes_to_chord(\"%s\", \"%s\", \"%s\")", note1, note2, note3);
}

void toNotes(char* chord) {
    dprintf(FD, "chord_to_notes(\"%s\")", chord);
}

void concatNotes(char * note1, char * note2, char * note3) {
    dprintf(FD, "concat_notes(\"%s\", \"%s\", \"%s\")", note1, note2, note3);
}

void isNote(char *note) {
    dprintf(FD, "is_note(\"%s\")", note);
}

void isChord(char *value) {
    dprintf(FD,"is_chord(\"%s\")", value);
}

void isChordSimple(char *value) {
    dprintf(FD,"is_chord_simple(\"%s\")", value);
}

void isChordGivenNotes(char *note1, char *note2, char *note3) {
    dprintf(FD,"is_chord_given_notes(\"%s\",\"%s\",\"%s\")", note1, note2, note3);
}

void printToChords(char *notes) {
    dprintf(FD, "strcpy(printChordAuxArray, \"%s\");\n", notes);
    dprintf(FD, "print_to_chords(printChordAuxArray)", notes);
}

// TODO: Hacer las funciones

/* Simbolos */

void openParValue() {
    dprintf(FD, "(");
}

void closeParValue() {
    dprintf(FD, ")");
}

void delimiterValue() {
    dprintf(FD, ";\n");
}

/* Data Format */

void getIntegerValue(int value) {
    dprintf(FD, "%d", value);
}

void getStringValue(char* string) {
    dprintf(FD, "%s", string);
}
