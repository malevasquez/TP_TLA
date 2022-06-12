%{

#include "bison-actions.h"

%}

%union {
	int num;
	char* string;
}

// IDs de los tokens generados desde Flex:
%token <string> START
%token <string> END

%token <string> PLUS
%token <string> MINUS
%token <string> MULTIPLY
%token <string> DIVIDE

%token <string> IF
%token <string> THEN
%token <string> ELSE
%token <string> END_IF

%token <string> DO_STATEMENT
%token <string> WHILE

%token GREATER
%token LOWER
%token EQUALS
%token NOT_EQUALS
%token AND
%token OR
%token NOT
%token TRUE
%token FALSE

%token PRINT_FUNCTION
%token PRINT_TO_CHORDS
%token CONCAT_NOTES
%token TO_NOTES
%token TO_CHORD
%token REPRODUCE_NOTE
%token REPRODUCE_CHORD
%token IS_NOTE
%token IS_CHORD
%token ASSIGN
%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS
%token DELIMITER
%token NOTE_TYPE
%token CHORD_TYPE
%token STRING_TYPE
%token INTEGER_TYPE

%token <num> INTEGER
%token <string> CHORD
%token <string> NOTE
%token <string> STRING
%token VARIABLE_NAME

%right ASSIGN
%left AND OR
%left GREATER LOWER EQUALS NOT_EQUALS
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left NOT

%start program

%%

program: start code end												
	;

start: START														{ ProgramGrammarAction($1); }
	;

end: END 															{ EndProgramGrammarAction($1); }
	;

code: instruction code
	| conditional code
	| {}	
	;

instruction: definition DELIMITER
	| assignment DELIMITER
	| print DELIMITER
	| concat_notes DELIMITER
	| to_notes DELIMITER
	| to_chord DELIMITER
	| reproduce_note DELIMITER
	| reproduce_chord DELIMITER
	| validate DELIMITER
	| print_to_chords DELIMITER
	;

assignment:
	definition ASSIGN str
	| definition ASSIGN expression
    | definition ASSIGN chord									
	| definition ASSIGN note
	| definition ASSIGN to_chord	
	| VARIABLE_NAME ASSIGN note	
	| VARIABLE_NAME ASSIGN expression								
	| VARIABLE_NAME ASSIGN chord									
	| VARIABLE_NAME ASSIGN str
	| VARIABLE_NAME ASSIGN to_chord			
	;

print:
	PRINT_FUNCTION chord													
	| PRINT_FUNCTION note												
	| PRINT_FUNCTION str												
	| PRINT_FUNCTION integer								
	| PRINT_FUNCTION VARIABLE_NAME
	;

print_to_chords:													
	PRINT_TO_CHORDS note note note
	| PRINT_TO_CHORDS VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	;

concat_notes: 
	CONCAT_NOTES VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| CONCAT_NOTES note note note
	;

to_notes:
	VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME TO_NOTES chord
	| VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME TO_NOTES VARIABLE_NAME
	;

to_chord:
	TO_CHORD VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| TO_CHORD note note note
	;

reproduce_note:
	REPRODUCE_NOTE note
	| REPRODUCE_NOTE VARIABLE_NAME
	;

reproduce_chord:
	REPRODUCE_CHORD chord
	| REPRODUCE_CHORD VARIABLE_NAME
	;

validate: IS_NOTE VARIABLE_NAME
	| IS_NOTE note
	| IS_CHORD VARIABLE_NAME
	| IS_CHORD VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| IS_CHORD note note note
	| IS_CHORD chord
	;

boolean:
	expression comparator_op expression
	| boolean AND boolean
	| boolean OR boolean
	| NOT boolean 
	| OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS
	| boolean_value
	| validate
	;

comparator_op:
	GREATER
	| LOWER
	| EQUALS
	| NOT_EQUALS
	;

boolean_value:
	TRUE
	| FALSE
	;

definition:
	INTEGER_TYPE VARIABLE_NAME
	| STRING_TYPE VARIABLE_NAME
	| NOTE_TYPE VARIABLE_NAME
	| CHORD_TYPE VARIABLE_NAME
	;

/*
type:
	INTEGER_TYPE
	| STRING_TYPE
	| NOTE_TYPE
	| CHORD_TYPE
	;
*/

/* ------------------------------------------------------ */ 
/*				    CONDITIONALS & CYCLES				  */
/* ------------------------------------------------------ */ 

conditional:
	conditional_if
	| conditional_if_else
	| conditional_while
	;

conditional_if: if_state OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS then_state code end_if_state
	;

conditional_if_else: if_state OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS then_state code else_state code end_if_state
	;

conditional_while: do_state code while_state OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS DELIMITER
	;

if_state:
	IF																{ IfGrammarAction($1); }
	;

then_state:
	THEN															{ ThenGrammarAction($1); }
	;

else_state:
	ELSE															{ ElseGrammarAction($1); }
	;

end_if_state:
	END_IF															{ EndIfGrammarAction($1); }
	;

do_state:
	DO_STATEMENT													{ DoGrammarAction($1); }
	;

while_state:
	WHILE															{ WhileGrammarAction($1); }
	;

/* ------------------------------------------------------ */ 
/*						OPERATIONS                        */
/* ------------------------------------------------------ */ 

expression:		
	VARIABLE_NAME op_sign expression
	| integer op_sign expression
	| OPEN_PARENTHESIS expression CLOSE_PARENTHESIS
	| VARIABLE_NAME
	| integer
	;

op_sign:
	PLUS 															{ PlusGrammarAction($1); }
	| MINUS 														{ MinusGrammarAction($1); }
	| MULTIPLY 														{ MultiplyGrammarAction($1); }
	| DIVIDE 														{ DivideGrammarAction($1); }
	;

/* ------------------------------------------------------ */ 
/*						DATA TYPES                        */
/* ------------------------------------------------------ */ 

integer:
	INTEGER															{ IntegerConstantGrammarAction($1); }
	;

str:
	STRING															{ StringValueGrammarAction($1); }
	;

chord:
	CHORD															{ ChordValueGrammarAction($1); }
	;

note:
	NOTE															{ NoteValueGrammarAction($1); }
	;

%%
