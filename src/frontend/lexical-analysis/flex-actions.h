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

	// Token propios
	START,
	END,

	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,

	IF,
	THEN,
	ELSE,
	END_IF,

	DO,
	WHILE,

	GREATER,
	LOWER,
	EQUALS,
	NOT_EQUALS,
	AND,
	OR,
	NOT,
	TRUE,
	FALSE,

	PRINT_FUNCTION,
	PRINT_TO_CHORDS,
	CONCAT_NOTES,
	TO_NOTES,
	TO_CHORD,
	REPRODUCE_NOTE,
	REPRODUCE_CHORD,
	IS_NOTE,
	IS_CHORD,

	ASSIGN,
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
	DELIMITER,
	
	NOTE_TYPE,
	CHORD_TYPE,
	STRING_TYPE,
	INTEGER_TYPE,

	// Tipos de dato.
	INTEGER,
	CHORD,
	NOTE,
	STRING,
	VARIABLE_NAME
} TokenID;

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

TokenID PatternAction(TokenID token, const char* message);
TokenID IntegerPatternAction(const char * lexeme);
TokenID ChordPatternAction(const char * lexeme);
TokenID NotePatternAction(const char * lexeme);
TokenID StringPatternAction(const char * lexeme);
TokenID VariableNamePatternAction(const char * lexeme);

void IgnoredPatternAction(const char * lexeme);
TokenID UnknownPatternAction(const char * lexeme);

#endif
