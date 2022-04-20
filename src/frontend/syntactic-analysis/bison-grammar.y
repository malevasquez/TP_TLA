%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token START
%token END
%token ASSIGN
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token GREATER
%token LOWER
%token EQUALS
%token NOT_EQUALS
%token AND
%token OR
%token NOT
%token TRUE
%token FALSE
%token IF
%token THEN
%token ELSE
%token END_IF
%token DO
%token WHILE
%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS
%token PRINT
%token NEW_LINE
%token MUSICAL_NOTE 
%token MUSICAL_CHORD
%token TO_NOTES
%token TO_CHORD
%token CONCAT_NOTES
%token REPRODUCE_CHORD
%token REPRODUCE_NOTE

%token DELIMITER
%token INTEGER
%token STRING
%token VARIABLE

// Reglas de asociatividad y precedencia (de menor a mayor):
%left PLUS MINUS
%left MULTIPLY DIVIDE

%%

program: start code end                                        {$$ = ProgramGrammarAction(0);}
    ;

start: START                                                   {$$ = ProgramGrammarAction(0);}
    ;

end: END                                                       {$$ = ProgramGrammarAction(0);}
    ;

code: instruction code
    | conditional code
    ;

instruction: 
    definition delimiter
    | assignment delimiter
    | print delimiter
    | concat_notes delimiter
    | chord_to_notes delimiter
    | notes_to_chord delimiter
    | reproduce_note delimiter
    | reproduce_chord delimiter
    ;

assignment:
    definition 
	| definition assign chord									
	| definition assign note									
	| variable assign expression								
	| variable assign string									
	| variable assign chord										
	;

expression:
	variable op_sign expression								
	| variable												
	| integer op_sign expression
	| integer
	| expression op_sign expression
	| factor
	;

factor: open_par expression close_par				
	;

conditional:
	conditional_if
	| conditional_if_else
	| conditional_while

conditional_if: if_def open_par boolean close_par then_def code end_if_def
	;

conditional_if_else: if_def open_par boolean close_par then_def code else_def code end_if_def
	;

conditional_while: 
	do_def code while_def open_par boolean close_par delimiter 
	;

if_def: IF 														
	;

then_def: THEN 													
	;

else_def: ELSE 													
	;

end_if_def: END_IF 												
	;

while_def: WHILE 												
	;

do_def: DO 														
	;

boolean:
	expression operator expression
	| boolean and_op boolean
	| boolean or_op boolean
	| not_op open_par boolean close_par
	| open_par boolean close_par
	;

operator:
	equal | notequal | lower | greater ;

print:
	PRINT chord													
	| PRINT note												
	| PRINT string												
	| PRINT integer												
	| PRINT variable											 
	| PRINT NEW_LINE
    ;

concat_notes:
	CONCAT_NOTES variable variable							
	;

chord_to_notes: TO_NOTES chord									
	;
	
notes_to_chord: TO_CHORD variable variable variable				
	;

reproduce_note: REPRODUCE_NOTE variable							
	;

reproduce_chord: REPRODUCE_CHORD variable						

open_par: OPEN_PARENTHESIS										
	;
close_par: CLOSE_PARENTHESIS									
	;

definition: type variable
    ;

op_sign:
	PLUS 													
	| MINUS 													
	| MULTIPLY 													
	| DIVIDE 													
	;

assign: ASSIGN
    ;

and_op: AND 													
	;

or_op: OR 											
	;

equal: EQUALS 											
	;

notequal: NOT_EQUALS 											
	;

not_op: NOT 													
	;

lower: LOWER 													
	;

greater: GREATER 												
	;

delimiter: DELIMITER
    ;

type: 
	INTEGER 													
	| STRING 												
	| MUSICAL_NOTE 											
    | MUSICAL_CHORD 									
	; 

variable: VARIABLE                                             
	;

integer: INTEGER                                               
	;

string: STRING                                                 
	;

note: MUSICAL_NOTE                                              
	;

chord: MUSICAL_CHORD                                           
	;

%%
