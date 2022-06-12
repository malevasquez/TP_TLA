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

unsigned IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval.num = atoi(lexeme);
	return INTEGER;
}

unsigned ChordPatternAction(const char * lexeme) {
    LogDebug("ChordPatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return CHORD;
}

unsigned NotePatternAction(const char * lexeme) {
    LogDebug("NotePatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return NOTE;
}

unsigned StringPatternAction(const char * lexeme) {
    LogDebug("StringPatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return STRING;
}

unsigned VariableNamePatternAction(const char * lexeme) {
    LogDebug("VariableNamePatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return VARIABLE_NAME;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

unsigned UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
