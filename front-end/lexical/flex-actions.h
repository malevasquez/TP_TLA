#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"

typedef enum TokenID {
    UNKNOWN = 0,
    YYUNDEF = 257,

    STRING,
    INTEGER,
    VARIABLE
} TokenID;

TokenID StringPatternAction(const char * lexeme);
TokenID IntegerPatternAction(const char* lexeme);
TokenID UnknownPatternAction(const char * lexeme);
TokenID VariablePatternAction(const char * lexeme)

#endif