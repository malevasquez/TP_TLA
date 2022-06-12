#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

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

/* ------------------------------------------------------ */ 
/*						  MARKERS                         */
/* ------------------------------------------------------ */ 

int ProgramGrammarAction(char* value) {
	LogDebug("ProgramGrammarAction(%s)", value);
	start_program();
	state.succeed = true;
	state.result = 0;
	return 0;
}

int EndProgramGrammarAction(char* value) {
	LogDebug("EndProgramGrammarAction(%s)", value);
	end_program();
	return 0;
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

/* ------------------------------------------------------ */ 
/*						OP SYMBOLS                        */
/* ------------------------------------------------------ */ 

int PlusGrammarAction(char * value) {
	LogDebug("PlusGrammarAction(%s)", value);
	plusValue();
	return 0;
}

int MinusGrammarAction(char * value) {
	LogDebug("MinusGrammarAction(%s)", value);
	minusValue();
	return 0;
}

int MultiplyGrammarAction(char * value) {
	LogDebug("MultiplyGrammarAction(%s)", value);
	multiplyValue();
	return 0;
}

int DivideGrammarAction(char * value) {
	LogDebug("DivideGrammarAction(%s)", value);
	divideValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*				    CONDITIONALS & CYCLES				  */
/* ------------------------------------------------------ */ 

int IfGrammarAction(char * value) {
	LogDebug("IfGrammarAction(%s)", value);
	ifValue();
	return 0;
}

int ThenGrammarAction(char * value) {
	LogDebug("ThenGrammarAction(%s)", value);
	thenValue();
	return 0;
}

int ElseGrammarAction(char * value) {
	LogDebug("ElseGrammarAction(%s)", value);
	elseValue();
	return 0;
}

int EndIfGrammarAction(char * value) {
	LogDebug("EndIfGrammarAction(%s)", value);
	endIfValue();
	return 0;
}

int DoGrammarAction(char * value) {
	LogDebug("DoGrammarAction(%s)", value);
	doStatementValue();
	return 0;
}

int WhileGrammarAction(char * value) {
	LogDebug("WhileGrammarAction(%s)", value);
	whileValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*						DATA TYPES                        */
/* ------------------------------------------------------ */ 

int IntegerConstantGrammarAction(const int value) {
	LogDebug("IntegerConstantGrammarAction(%d)", value);
	getIntegerValue(value);
	return value;
}

int StringValueGrammarAction(char* str) {
	LogDebug("StringValueGrammarAction(%s)", str);
	getStringValue(str);
	return 0;
}

int NoteValueGrammarAction(char* note) {
	LogDebug("NoteValueGrammarAction(%s)", note);
	print_note(note);
	return 0;
}

int ChordValueGrammarAction(char* chord) {
	LogDebug("ChordValueGrammarAction(%s)", chord);
	print_chord(chord);
	return 0;
}