#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

TokenID StringPatternAction(const char * lexeme) {
    LogDebug("StringPatternAction: '%s'.", lexeme);
    strcpy(yyltext, lexeme);
	return STRING;
}

TokenID IntegerPatternAction(consta char* lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}