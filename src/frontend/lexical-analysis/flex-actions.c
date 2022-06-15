#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

unsigned PatternAction(unsigned token, const char* message) {
	LogDebug(message);
	return token;
}

/* Marcadores de inicio y fin */

unsigned StartPatternAction(char * lexeme) {
	LogDebug("StartPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return START;
}

unsigned EndPatternAction(char * lexeme) {
	LogDebug("EndPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return END;
}

/* Asignacion */

unsigned AssignPatternAction(char * lexeme) {
	LogDebug("AssignPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return ASSIGN;
}

/* Signos de operacion */

unsigned PlusPatternAction(char * lexeme) {
	LogDebug("PlusPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return PLUS;
}

unsigned MinusPatternAction(char * lexeme) {
	LogDebug("MinusPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return MINUS;
}

unsigned MultiplyPatternAction(char * lexeme) {
	LogDebug("MultiplyPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return MULTIPLY;
}

unsigned DividePatternAction(char * lexeme) {
	LogDebug("DividePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return DIVIDE;
}

/* Condicionales y Ciclos */

unsigned IfPatternAction(char * lexeme) {
	LogDebug("IfPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return IF;
}

unsigned ThenPatternAction(char * lexeme) {
	LogDebug("ThenPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return THEN;
}

unsigned ElsePatternAction(char * lexeme) {
	LogDebug("ElsePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return ELSE;
}

unsigned EndIfPatternAction(char * lexeme) {
	LogDebug("EndIfPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return END_IF;
}

unsigned DoStatementPatternAction(char * lexeme) {
	LogDebug("DoStatementPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return DO_STATEMENT;
}

unsigned WhilePatternAction(char * lexeme) {
	LogDebug("WhilePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return WHILE;
}

/* Signos de comparacion */

unsigned GreaterPatternAction(char * lexeme) {
	LogDebug("GreaterPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return GREATER;
}

unsigned LowerPatternAction(char * lexeme) {
	LogDebug("LowerPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return LOWER;
}

unsigned EqualsPatternAction(char * lexeme) {
	LogDebug("EqualsPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return EQUALS;
}

unsigned NotEqualsPatternAction(char * lexeme) {
	LogDebug("NotEqualsPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return NOT_EQUALS;
}

/* Operadores logicos */

unsigned AndPatternAction(char * lexeme) {
	LogDebug("AndPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return AND;
}

unsigned OrPatternAction(char * lexeme) {
	LogDebug("OrPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return OR;
}

unsigned NotPatternAction(char * lexeme) {
	LogDebug("NotPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return NOT;
}

/* Valores de verdad */

unsigned TruePatternAction(char * lexeme) {
	LogDebug("TruePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return TRUE;
}

unsigned FalsePatternAction(char * lexeme) {
	LogDebug("FalsePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return FALSE;
}

/* Funciones */

unsigned PrintPatternAction(char * lexeme) {
	LogDebug("PrintPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return PRINT_FUNCTION;
}

unsigned PrintToChordsPatternAction(char * lexeme) {
	LogDebug("PrintToChordsPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return PRINT_TO_CHORDS;
}

unsigned ConcatNotesPatternAction(char * lexeme) {
	LogDebug("ConcatNotesPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return CONCAT_NOTES;
}

unsigned ToNotesPatternAction(char * lexeme) {
	LogDebug("ToNotesPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return TO_NOTES;
}

unsigned ToChordPatternAction(char * lexeme) {
	LogDebug("ToChordPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return TO_CHORD;
}

unsigned ReproduceNotePatternAction(char * lexeme) {
	LogDebug("ReproduceNotePatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return REPRODUCE_NOTE;
}

unsigned CreateMusicScorePatternAction(char * lexeme) {
	LogDebug("CreateMusicScorePatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return CREATE_MUSIC_SCORE;
}

unsigned IsNotePatternAction(char * lexeme) {
	LogDebug("IsNotePatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return IS_NOTE;
}

unsigned IsChordPatternAction(char * lexeme) {
	LogDebug("IsChordPatternAction: '%s'.", lexeme);
	yylval.func = lexeme;
	return IS_CHORD;
}


/* Symbols */

unsigned OpenParenthesisPatternAction(char * lexeme) {
	LogDebug("OpenParenthesisPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return OPEN_PARENTHESIS;
}

unsigned CloseParenthesisPatternAction(char * lexeme) {
	LogDebug("CloseParenthesisPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return CLOSE_PARENTHESIS;
}

unsigned DelimiterPatternAction(char * lexeme) {
	LogDebug("DelimiterPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return DELIMITER;
}

/* Data Types */

unsigned NoteTypePatternAction(char * lexeme) {
	LogDebug("NoteTypePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return NOTE_TYPE;
}

unsigned ChordTypePatternAction(char * lexeme) {
	LogDebug("ChordTypePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return CHORD_TYPE;
}

unsigned StringTypePatternAction(char * lexeme) {
	LogDebug("StringTypePatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return STRING_TYPE;
}

unsigned IntegerTypePatternAction(char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval.string = lexeme;
	return INTEGER_TYPE;
}

/* Data Format */

unsigned IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval.num = atoi(lexeme);
	return INTEGER;
}

unsigned ChordPatternAction( char * lexeme) {
    LogDebug("ChordPatternAction: '%s'.", lexeme);
    yylval.string = lexeme;
	return CHORD;
}

unsigned NotePatternAction( char * lexeme) {
    LogDebug("NotePatternAction: '%s'.", lexeme);
    yylval.string = lexeme;
	return NOTE;
}

unsigned StringPatternAction( char * lexeme) {
    LogDebug("StringPatternAction: '%s'.", lexeme);
    yylval.string = lexeme;
	return STRING;
}

unsigned VariableNamePatternAction( char * lexeme) {
    LogDebug("VariableNamePatternAction: '%s'.", lexeme);
    yylval.string = lexeme;
	return VARIABLE_NAME;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

unsigned UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
