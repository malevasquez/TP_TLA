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
    definition assign expression								{ $$ = AssignAction($1, $2, $3); }
	| definition assign string									{ $$ = AssignAction($1, $2, $3); }
	| definition assign chord									{ $$ = AssignAction($1, $2, $3); }
	| definition assign note									{ $$ = AssignAction($1, $2, $3); }
	| variable assign expression								{ $$ = AssignAction($1, $2, $3); }
	| variable assign string									{ $$ = AssignAction($1, $2, $3); }
	| variable assign chord										{ $$ = AssignAction($1, $2, $3); }
	;

expression:
	variable op_sign expression									{ $$ = VariableGrammarAction($1); }
	| variable													{ $$ = VariableGrammarAction($1); }
	| integer op_sign expression
	| integer
	| open_par expression close_par op_sign expression
	| open_par expression close_par
	;

/* expression: 
	| expression PLUS expression								{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression MINUS expression								{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MULTIPLY expression							{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIVIDE expression								{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
	; */

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| constant													{ $$ = ConstantFactorGrammarAction($1); }
	;


definition: type VARIABLE 										{ $$ = VariableTypeDefinition($1,$2); }
	;

/* ------------------------------------------------------ */ 
/*					     FUNCTION                         */
/* ------------------------------------------------------ */ 

print:
	PRINT chord													{ $$ = PrintChordAction($2); }
	| PRINT note												{ $$ = PrintNoteAction($2); }
	| PRINT string												{ $$ = PrintStringAction($2); }
	| PRINT integer												{ $$ = PrintIntegerAction($2); }
	| PRINT variable											{ $$ = PrintVariableAction($2); }
	| PRINT NEW_LINE											{ $$ = PrintNewLineAction($2); }
	;

concat_notes:
	CONCAT_NOTES variable variable								{ $$ = ConcatNotesAction($2, $3); }
	;

chord_to_notes: TO_NOTES chord									{ $$ = ToNotesAction($2); }
	;
	
notes_to_chord: TO_CHORD note note note							{ $$ = ToChordAction($2, $3, $4); }
	;

reproduce_note: REPRODUCE_NOTE note								{ $$ = ReproduceNoteAction($2); }
	;

reproduce_chord: REPRODUCE_CHORD chord							{ $$ = ReproduceChordAction($2); }

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
	do_def program while_def open_par boolean close_par delimiter { printf("\n"); }
	;

if_def: IF 														{ printf("if "); }
	;

then_def: THEN 													{ printf(" {\n"); }
	;

else_def: ELSE 													{ printf("}\n else {"); }
	;

end_if_def: END_IF 												{ printf("}\n"); }
	;

while_def: WHILE 												{ printf("} while "); }
	;

do_def: DO 														{ printf("do { \n"); }
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
	PLUS 														{ printf(" + "); }
	| MINUS 													{ printf(" - "); }
	| MULTIPLY 													{ printf(" * "); }
	| DIVIDE 													{ printf(" / "); }
	;

open_par: OPEN_PARENTHESIS										{ printf("("); }
	;
close_par: CLOSE_PARENTHESIS									{ printf(")"); }
	;

and_op: AND 													{ printf(" && "); }
	;

or_op: OR 														{ printf(" || "); }
	;

equal: EQUALS 													{ printf("=="); }
	;

notequal: NOT_EQUALS 											{ printf("!="); }
	;

not_op: NOT 													{ printf("!"); }
	;

lower: LOWER 													{ printf("<"); }
	;

greater: GREATER 												{ printf(">"); }
	;

assign: ASSIGN 													{ printf(" = "); }
	;

delimiter: DELIMITER 											{ printf(";\n"); }  
	;

/* ------------------------------------------------------ */ 
/*                   	   TYPE                           */
/* ------------------------------------------------------ */ 

type: 
	INTEGER 													{ $$ = 0; printf("int "); } 
	| STRING 													{ $$ = 1; printf("char *"); }
	| MUSICAL_NOTE 												{ $$ = 2; printf("char *"); }
    | MUSICAL_CHORD 											{ $$ = 3; printf("char "); }
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
