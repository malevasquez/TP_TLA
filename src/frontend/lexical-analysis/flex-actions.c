#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID PatternAction(TokenID token, const char* message) {
	LogDebug(message);
	return token;
}

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID ChordPatternAction(const char * lexeme) {
    LogDebug("ChordPatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return CHORD;
}

TokenID NotePatternAction(const char * lexeme) {
    LogDebug("NotePatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return NOTE;
}

TokenID StringPatternAction(const char * lexeme) {
    LogDebug("StringPatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return STRING;
}

TokenID VariableNamePatternAction(const char * lexeme) {
    LogDebug("VariableNamePatternAction: '%s'.", lexeme);
    // strcpy(yytext, lexeme);
	return VARIABLE_NAME;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
