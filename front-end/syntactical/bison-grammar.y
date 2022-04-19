%{
    #include "bison-actions.h"
%}

%union {
  char *string;
  double number;
}

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
%token <number> INTEGER
%token <string> STRING
%token <string> VARIABLE

%left PLUS MINUS
%left MULTIPLY DIVIDE

%type<string> definition
%type<number> type
%type<number> traduce
%type<number> concat
%type<string> var

%start init

%%

init: 
	start program end
	;

start: {$$ = StartAction();};

program: conditional program
    | instruction program
	;

end: {$$ = EndAction();};

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
    definition assign expression								{ $$ = AssignAction($1); }
	| definition assign string									{ $$ = AssignAction($1); }
	| definition assign chord									{ $$ = AssignAction($1); }
	| definition assign note									{ $$ = AssignAction($1); }
	| variable assign expression								{ $$ = AssignAction($1); }
	| variable assign string									{ $$ = AssignAction($1); }
	| variable assign chord										{ $$ = AssignAction($1); }
	;

expression:
	variable op_sign expression									{ $$ = AssignAction($1); }
	| variable													{ $$ = AssignAction($1); }
	| integer op_sign expression
	| integer
	| open_par expression close_par op_sign expression
	| open_par expression close_par
	;

definition: type VARIABLE 										{ $$ = VariableTypeDefinition($1,$2); }
	;

/* ------------------------------------------------------ */ 
/*					     FUNCTION                         */
/* ------------------------------------------------------ */ 

print:
	PRINT chord													{ $$ = PrintStringAction($2); }
	| PRINT note												{ $$ = PrintStringAction($2); }
	| PRINT string												{ $$ = PrintStringAction($2); }
	| PRINT integer												{ $$ = PrintIntegerAction($2); }
	| PRINT variable											{ $$ = PrintVariableAction($2); }
	| PRINT NEW_LINE											{ $$ = PrintStringAction($2); }
	;

concat_notes:
	CONCAT_NOTES variable variable								{ $$ = ConcatNotesAction($2, $3); }
	;

chord_to_notes: TO_NOTES chord									{ $$ = ToNotesAction($2); }
	;
	
notes_to_chord: TO_CHORD variable variable variable				{ $$ = ToChordAction($2, $3, $4); }
	;

reproduce_note: REPRODUCE_NOTE variable							{ $$ = ReproduceNoteAction($2); }
	;

reproduce_chord: REPRODUCE_CHORD variable						{ $$ = ReproduceChordAction($2); }

/* ------------------------------------------------------ */ 
/*					    CONDITIONAL                       */
/* ------------------------------------------------------ */ 

conditional:
	conditional_if
	| conditional_if_else
	| conditional_while

conditional_if: if_def open_par boolean close_par then_def program end_if_def
	;

conditional_if_else: if_def open_par boolean close_par then_def program else_def program end_if_def
	;

conditional_while: 
	do_def program while_def open_par boolean close_par delimiter { Print("\n"); }
	;

if_def: IF 														{ Print("if "); }
	;

then_def: THEN 													{ Print(" {\n"); }
	;

else_def: ELSE 													{ Print("}\n else {"); }
	;

end_if_def: END_IF 												{ Print("}\n"); }
	;

while_def: WHILE 												{ Print("} while "); }
	;

do_def: DO 														{ Print("do { \n"); }
	;

/* ------------------------------------------------------ */ 
/*						OPERATIONS                        */
/* ------------------------------------------------------ */ 

boolean:
	expression operator expression
	| boolean and_op boolean
	| boolean or_op boolean
	| not_op open_par boolean close_par
	| open_par boolean close_par
	;

operator:
	equal | notequal | lower | greater ;

/* ------------------------------------------------------ */ 
/*						SYMBOLS                           */
/* ------------------------------------------------------ */ 

op_sign:
	PLUS 														{ Print(" + "); }
	| MINUS 													{ Print(" - "); }
	| MULTIPLY 													{ Print(" * "); }
	| DIVIDE 													{ Print(" / "); }
	;

open_par: OPEN_PARENTHESIS										{ Print("("); }
	;
close_par: CLOSE_PARENTHESIS									{ Print(")"); }
	;

and_op: AND 													{ Print(" && "); }
	;

or_op: OR 														{ Print(" || "); }
	;

equal: EQUALS 													{ Print("=="); }
	;

notequal: NOT_EQUALS 											{ Print("!="); }
	;

not_op: NOT 													{ Print("!"); }
	;

lower: LOWER 													{ Print("<"); }
	;

greater: GREATER 												{ Print(">"); }
	;

assign: ASSIGN 													{ Print(" = "); }
	;

delimiter: DELIMITER 											{ Print(";\n"); }  
	;

/* ------------------------------------------------------ */ 
/*                   	   TYPE                           */
/* ------------------------------------------------------ */ 

type: 
	INTEGER 													{ $$ = 0; Print("int "); } 
	| STRING 													{ $$ = 1; Print("char *"); }
	| MUSICAL_NOTE 												{ $$ = 2; Print("char *"); }
    | MUSICAL_CHORD 											{ $$ = 3; Print("char "); }
	; 

variable: VARIABLE                                              { $$ = VariableGrammarAction($1); }
	;

integer: INTEGER                                                { $$ = IntegerConstantGrammarAction($1); }
	;

string: STRING                                                  { $$ = StringConstantGrammarAction($1); }
	;

note: MUSICAL_NOTE                                              { $$ = MusicalNoteConstantGrammarAction($1); }
	;

chord: MUSICAL_CHORD                                            { $$ = MusicalChordConstantGrammarAction($1); }
	;
