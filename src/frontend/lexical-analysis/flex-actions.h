#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include <string.h>

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
typedef enum TokenID {

	// Por defecto, el valor "0" hace fallar el analizador sintáctico.
	UNKNOWN = 0,

	// Código de error de Bison, que permite abortar el escaneo de lexemas cuando
	// se presente un patrón desconocido. El número "257" coincide con el valor
	// que Bison le otorga por defecto, pero además permite que el resto de
	// tokens continúen desde el valor "258" lo que permite proteger los IDs
	// internos que Bison reserva para crear "tokens literales":
	YYUNDEF = 257,

	START,
    END,
    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    GREATER,
    LOWER,
    EQUALS,
    NOT_EQUALS,
    AND,
    OR,
    NOT,
    TRUE,
    FALSE,
    IF,
    THEN,
    ELSE,
    END_IF,
    DO,
    WHILE,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    PRINT,
    NEW_LINE,
    MUSICAL_NOTE,
    MUSICAL_CHORD,
    TO_NOTES,
    TO_CHORD,
    CONCAT_NOTES,
    REPRODUCE_CHORD,
    REPRODUCE_NOTE,
    DELIMITER,
    INTEGER,
    STRING,
    VARIABLE
} TokenID;

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

TokenID StringPatternAction(const char * lexeme);
TokenID IntegerPatternAction(const char* lexeme);
TokenID UnknownPatternAction(const char * lexeme);

#endif
