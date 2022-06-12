#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"
#include <string.h>

#define YYUNDEF 257

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
/* typedef enum TokenID {

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

	DO_STATEMENT,
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
} TokenID; */

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

unsigned PatternAction(unsigned token, const char* message);

/* Marcadores de inicio y fin */

unsigned StartPatternAction(char * lexeme);
unsigned EndPatternAction(char * lexeme);

/* Asignacion */

unsigned AssignPatternAction(char * lexeme);

/* Signos de operacion */

unsigned PlusPatternAction(char * lexeme);
unsigned MinusPatternAction(char * lexeme);
unsigned MultiplyPatternAction(char * lexeme);
unsigned DividePatternAction(char * lexeme);

/* Condicionales y Ciclos */

unsigned IfPatternAction(char * lexeme);
unsigned ThenPatternAction(char * lexeme);
unsigned ElsePatternAction(char * lexeme);
unsigned EndIfPatternAction(char * lexeme);
unsigned DoStatementPatternAction(char * lexeme);
unsigned WhilePatternAction(char * lexeme);

/* Signos de comparacion */

unsigned GreaterPatternAction(char * lexeme);
unsigned LowerPatternAction(char * lexeme);
unsigned EqualsPatternAction(char * lexeme);
unsigned NotEqualsPatternAction(char * lexeme);

/* Operadores logicos */

unsigned AndPatternAction(char * lexeme);
unsigned OrPatternAction(char * lexeme);
unsigned NotPatternAction(char * lexeme);

/* Valores de verdad */

unsigned TruePatternAction(char * lexeme);
unsigned FalsePatternAction(char * lexeme);

/* Funciones */
unsigned PrintPatternAction(char * lexeme);
unsigned PrintToChordsPatternAction(char * lexeme);
unsigned ConcatNotesPatternAction(char * lexeme);
unsigned ToNotesPatternAction(char * lexeme);
unsigned ToChordPatternAction(char * lexeme);
unsigned ReproduceNotePatternAction(char * lexeme);
unsigned ReproduceChordPatternAction(char * lexeme);
unsigned IsNotePatternAction(char * lexeme);
unsigned IsChordPatternAction(char * lexeme);

/* Simbolos */

unsigned OpenParenthesisPatternAction(char * lexeme);
unsigned CloseParenthesisPatternAction(char * lexeme);
unsigned DelimiterPatternAction(char * lexeme);

/* Data Types */

unsigned NoteTypePatternAction(char * lexeme);
unsigned ChordTypePatternAction(char * lexeme);
unsigned StringTypePatternAction(char * lexeme);
unsigned IntegerTypePatternAction(char * lexeme);

/* Data Format */

unsigned IntegerPatternAction(const char * lexeme);
unsigned ChordPatternAction(char * lexeme);
unsigned NotePatternAction(char * lexeme);
unsigned StringPatternAction(char * lexeme);
unsigned VariableNamePatternAction(char * lexeme);

void IgnoredPatternAction(const char * lexeme);
unsigned UnknownPatternAction(const char * lexeme);

#endif
