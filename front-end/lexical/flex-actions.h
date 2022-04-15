#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"

typedef enum TokenID {
    UNKNOWN = 0,
    YYUNDEF = 257,

    STRING,
    INTEGER
} TokenID;

TokenID StringPatternAction(const char * lexeme);
TokenID IntegerPatternAction(const char* lexeme);
TokenID UnknownPatternAction(const char * lexeme);

#endif