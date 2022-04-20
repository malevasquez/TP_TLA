#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID StringPatternAction(const char * lexeme) {
    LogDebug("StringPatternAction: '%s'.", lexeme);
    strcpy(yytext, lexeme);
	return STRING;
}

TokenID IntegerPatternAction(const char* lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
