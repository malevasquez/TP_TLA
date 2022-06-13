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
/*						OPERACIONES                       */
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
/*			      CONDITIONALES & CYCLOS				  */
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
/*						COMPARACION                       */
/* ------------------------------------------------------ */

int GreaterGrammarAction(char * value) {
	LogDebug("GreaterGrammarAction(%s)", value);
	greaterValue();
	return 0;
}

int LowerGrammarAction(char * value) {
	LogDebug("LowerGrammarAction(%s)", value);
	lowerValue();
	return 0;
}

int EqualGrammarAction(char * value) {
	LogDebug("EqualGrammarAction(%s)", value);
	equalValue();
	return 0;
}

int NotEqualGrammarAction(char * value) {
	LogDebug("NotEqualGrammarAction(%s)", value);
	notEqualValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*					 	 OP LOGICOS                       */
/* ------------------------------------------------------ */

int AndGrammarAction(char * value) {
	LogDebug("AndEqualGrammarAction(%s)", value);
	andValue();
	return 0;
}

int OrGrammarAction(char * value) {
	LogDebug("OrGrammarAction(%s)", value);
	orValue();
	return 0;
}

int NotGrammarAction(char * value) {
	LogDebug("NotGrammarAction(%s)", value);
	notValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*				   	  VALORES DE VERDAD                   */
/* ------------------------------------------------------ */

int TrueGrammarAction(char * value) {
	LogDebug("TrueGrammarAction(%s)", value);
	trueValue();
	return 0;
}

int FalseGrammarAction(char * value) {
	LogDebug("FalseGrammarAction(%s)", value);
	falseValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*						 FUNCIONES                        */
/* ------------------------------------------------------ */ 

int PrintIntegerGrammarAction(int value) {
	LogDebug("PrintIntegerGrammarAction(%d)", value);
	printNum(value);
	return 0;
}

int PrintStringGrammarAction(char * value) {
	LogDebug("PrintStringGrammarAction(%s)", value);
	printStr(value);
	return 0;
}

int PrintChordGrammarAction(char * value) {
	LogDebug("PrintChordGrammarAction(%s)", value);
	print_chord(value);
	return 0;
}

int PrintNoteGrammarAction(char * value) {
	LogDebug("PrintNoteGrammarAction(%s)", value);
	print_note(value);
	return 0;
}

// TODO: Check if strtok use is valid
int ToChordGrammarAction(char* func, char* notes) {
	char delimiter[] = " ";

	func = strtok(func, delimiter);

	char *note1, *note2, *note3;

	note1 = strtok(notes, delimiter);
	note2 = strtok(NULL, delimiter);
	note3 = strtok(NULL, delimiter);
	toChord(note1, note2, note3);
	LogDebug("ToChordGrammarAction(%s, %s, %s, %s)", func, note1, note2, note3);
	return 0;
}

int ToNotesGrammarAction(char * func, char * chord) {
	char delimiter[] = " ";
	func = strtok(func, delimiter);

	LogDebug("ToNotesGrammarAction(%s, %s)", func, chord);
	toNotes(chord);
	return 0;
}

int ConcatNotesGrammarAction(char * func, char * notes) {
	char delimiter[] = " ";

	func = strtok(func, delimiter);

	char *note1, *note2, *note3;

	note1 = strtok(notes, delimiter);
	note2 = strtok(NULL, delimiter);
	note3 = strtok(NULL, delimiter);
	concatNotes(note1, note2, note3);
	LogDebug("ConcatNotesGrammarAction(%s, %s, %s, %s)", func, note1, note2, note3);
	
	return 0;
}

/* ------------------------------------------------------ */ 
/*						 SIMBOLOS                         */
/* ------------------------------------------------------ */ 

int OpenParGrammarAction(char * value) {
	LogDebug("OpenParGrammarAction(%s)", value);
	openParValue();
	return 0;
}

int CloseParGrammarAction(char * value) {
	LogDebug("CloseParGrammarAction(%s)", value);
	closeParValue();
	return 0;
}

int DelimiterGrammarAction(char * value) {
	LogDebug("DelimiterGrammarAction(%s)", value);
	delimiterValue();
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