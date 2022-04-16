#include "../../backend/domain-specific/logic.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */


void StartAction() {
    printf("#include <stdio.h>\n");
    printf("#include <stlib.h>\n");
    printf("#include <string.h>\n");
    printf("int main() {\n");
}

void EndAction() {
    printf("return 0;}");    
}

void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(const int value) {
	LogDebug("ProgramGrammarAction(%d)", value);
	state.succeed = true;
	state.result = value;
	return value;
}

int AdditionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("AdditionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Add(leftValue, rightValue);
}

int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("SubtractionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Subtract(leftValue, rightValue);
}

int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("MultiplicationExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Multiply(leftValue, rightValue);
}

int DivisionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("DivisionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Divide(leftValue, rightValue);
}

int FactorExpressionGrammarAction(const int value) {
	LogDebug("FactorExpressionGrammarAction(%d)", value);
	return value;
}

int ExpressionFactorGrammarAction(const int value) {
	LogDebug("ExpressionFactorGrammarAction(%d)", value);
	return value;
}

int ConstantFactorGrammarAction(const int value) {
	LogDebug("ConstantFactorGrammarAction(%d)", value);
	return value;
}

int IntegerConstantGrammarAction(const int value) {
	LogDebug("IntegerConstantGrammarAction(%d)", value);
	return value;
}

//Falta hacer el VariableConstantGrammarAction()

char* StringConstantGrammarAction(const char* value) {
    LogDebug("StringConstantGrammarAction(%s)", value);
    return value;
}

char* MusicalNoteConstantGrammarAction(const char* value) {
    LogDebug("MusicalNoteConstantGrammarAction(%s)",value);
    return value;
}

char MusicalChordConstantGrammarAction(const char value) {
    LogDebug("MusicalChordConstantGrammarAction(%c)",value);
    return value;
}

char* VariableTypeDefinition(char* type, char* variable) {
    LogDebug("VariableTypeDefinition(%s, %s)",type, variable);
    return VariableTypeDefinitionImplementation(type, variable);
}


