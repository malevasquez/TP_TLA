%{

#include "bison-actions.h"

%}

%union {
	int num;
	char* string;
	char* func;
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

%token <string> GREATER
%token <string> LOWER
%token <string> EQUALS
%token <string> NOT_EQUALS
%token <string> AND
%token <string> OR
%token <string> NOT
%token <string> TRUE
%token <string> FALSE

%token PRINT_FUNCTION
%token PRINT_TO_CHORDS
%token CONCAT_NOTES
%token <func> TO_NOTES
%token <func> TO_CHORD
%token REPRODUCE_NOTE
%token REPRODUCE_CHORD
%token IS_NOTE
%token IS_CHORD
%token ASSIGN
%token <string> OPEN_PARENTHESIS
%token <string> CLOSE_PARENTHESIS
%token <string> DELIMITER
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

instruction: definition delimiter
	| assignment delimiter
	| print delimiter
	| concat_notes delimiter
	| to_notes delimiter
	| to_chord delimiter
	| reproduce_note delimiter
	| reproduce_chord delimiter
	| validate delimiter
	| print_to_chords delimiter
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
	PRINT_FUNCTION CHORD											{ PrintChordGrammarAction($2); }
	| PRINT_FUNCTION NOTE											{ PrintNoteGrammarAction($2); }
	| PRINT_FUNCTION STRING											{ PrintStringGrammarAction($2); }
	| PRINT_FUNCTION INTEGER										{ PrintIntegerGrammarAction($2); }
	| PRINT_FUNCTION VARIABLE_NAME
	;

print_to_chords:													
	PRINT_TO_CHORDS note note note									{ }
	| PRINT_TO_CHORDS VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME		{ }
	;

concat_notes: 
	CONCAT_NOTES VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME
	| CONCAT_NOTES note note note
	;

to_notes:
	TO_NOTES CHORD													{ ToNotesGrammarAction($1, $2); }
	| TO_NOTES VARIABLE_NAME
	;

to_chord:
	TO_CHORD VARIABLE_NAME VARIABLE_NAME VARIABLE_NAME				{ }
	| TO_CHORD NOTE NOTE NOTE										{ ToChordGrammarAction($1, $2); }
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
/*					 	   BOOLEAN						  */
/* ------------------------------------------------------ */ 

/* TODO: Chequear que este bien */
boolean:
	expression comparator_op expression
	| boolean_op and_op boolean_op
	| boolean_op or_op boolean_op
	| not_op boolean_op
	| boolean_value
	| validate
	;

boolean_op:
	expression
	| boolean_exp
	| validate
	;

boolean_exp:
	open_par boolean close_par
	| boolean_value

comparator_op:
	GREATER															{ GreaterGrammarAction($1); }
	| LOWER															{ LowerGrammarAction($1); }
	| EQUALS														{ EqualGrammarAction($1); }
	| NOT_EQUALS													{ NotEqualGrammarAction($1); }
	;

boolean_value:
	TRUE															{ TrueGrammarAction($1); }
	| FALSE															{ FalseGrammarAction($1); }
	;

and_op:
	AND																{ AndGrammarAction($1); }
	;

or_op:
	OR																{ OrGrammarAction($1); }
	;

not_op:
	NOT																{ NotGrammarAction($1); }
	;

/* ------------------------------------------------------ */ 
/*				    CONDITIONALS & CYCLES				  */
/* ------------------------------------------------------ */ 

conditional:
	conditional_if
	| conditional_if_else
	| conditional_while
	;

conditional_if: if_state open_par boolean close_par then_state code end_if_state
	;

conditional_if_else: if_state open_par boolean close_par then_state code else_state code end_if_state
	;

conditional_while: do_state code while_state open_par boolean close_par delimiter
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
	| open_par expression close_par
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
/*					  	  SYMBOLS                         */
/* ------------------------------------------------------ */ 

open_par:
	OPEN_PARENTHESIS												{ OpenParGrammarAction($1); }
	;

close_par:
	CLOSE_PARENTHESIS												{ CloseParGrammarAction($1); }
	;

delimiter:
	DELIMITER														{ DelimiterGrammarAction($1); }
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
