%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token START
%token END

%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE

%token IF
%token THEN
%token ELSE
%token END_IF

%token DO
%token WHILE

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

%token INTEGER
%token CHORD
%token NOTE
%token STRING
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

start: START														{ $$ = ProgramGrammarAction($1); }
	;

end: END 															{ $$ = EndProgramGrammarAction($1); }
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
	definition ASSIGN STRING
	| definition ASSIGN expression
    | definition ASSIGN CHORD									
	| definition ASSIGN NOTE
	| definition ASSIGN to_chord	
	| VARIABLE_NAME ASSIGN NOTE	
	| VARIABLE_NAME ASSIGN expression								
	| VARIABLE_NAME ASSIGN CHORD									
	| VARIABLE_NAME ASSIGN STRING
	| VARIABLE_NAME ASSIGN to_chord			
	;

print:
	PRINT_FUNCTION CHORD													
	| PRINT_FUNCTION NOTE												
	| PRINT_FUNCTION STRING												
	| PRINT_FUNCTION INTEGER								
	| PRINT_FUNCTION VARIABLE_NAME
	;

print_to_chords:													
	PRINT_TO_CHORDS note note note
	;

note:
	NOTE
	| VARIABLE_NAME
	;

concat_notes: 
	CONCAT_NOTES VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| CONCAT_NOTES NOTE NOTE NOTE
	;

to_notes:
	VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME TO_NOTES CHORD
	| VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME TO_NOTES VARIABLE_NAME
	;

to_chord:
	TO_CHORD VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| TO_CHORD NOTE NOTE NOTE
	;

reproduce_note:
	REPRODUCE_NOTE NOTE
	| REPRODUCE_NOTE VARIABLE_NAME
	;

reproduce_chord:
	REPRODUCE_CHORD CHORD
	| REPRODUCE_CHORD VARIABLE_NAME
	;

validate: IS_NOTE VARIABLE_NAME
	| IS_NOTE NOTE
	| IS_CHORD VARIABLE_NAME
	| IS_CHORD VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| IS_CHORD NOTE NOTE NOTE
	| IS_CHORD CHORD
	;

conditional:
	conditional_if
	| conditional_if_else
	| conditional_while
	;

conditional_if: IF OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS THEN code END_IF
	;

conditional_if_else: IF OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS THEN code ELSE code END_IF
	;

conditional_while: DO code WHILE OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS DELIMITER
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
/*						OPERATIONS                        */
/* ------------------------------------------------------ */ 

expression:		
	VARIABLE_NAME op_sign expression
	| INTEGER op_sign expression
	| OPEN_PARENTHESIS expression CLOSE_PARENTHESIS
	| VARIABLE_NAME
	| INTEGER
	;

op_sign:
	PLUS 													
	| MINUS 													
	| MULTIPLY 													
	| DIVIDE 													
	;

%%
