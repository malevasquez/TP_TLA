%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Patrones reutilizables. */
crlf			    \r\n
endline			    \n
whitespace		    [ \f\n\r\t\v]
string              \"[^\n\r]*\"
variable_name 	    [a-zA-Z]+[_0-9A-Za-z]*
integer 	        [-]?[0-9]+
chord               [A-G]
note                (do|re|mi|fa|sol|la|si)#?


%%

"start"                                     { return PatternAction(START, "start"); }
"end"                                       { return END; }
"is"                                        { return ASSIGN; }

"plus"                                      {return PLUS;}
"minus"                                     {return MINUS;}     
"times"                                     {return MULTIPLY;}
"by"                                        {return DIVIDE;}

"if"                                        { return IF; }
"then"                                      { return THEN; }
"else"                                      { return ELSE; }
"end_if"                                    { return END_IF; }

"compute"                                   { return DO; }
"while"                                     { return WHILE; }

">"                                         {return GREATER;}
"<"                                         {return LOWER;}
"="                                         {return EQUALS;}
"!="                                        {return NOT_EQUALS;}
"and"                                       {return AND;}
"or"                                        {return OR;}
"not"                                       {return NOT;}
"true"                                      {return TRUE;}
"false"                                     {return FALSE;}

"print"                                     { return PRINT_FUNCTION; }
"print_to_chords"                           { return PRINT_TO_CHORDS; }
"concat_notes"                              { return CONCAT_NOTES; }
"to_notes"                                  { return TO_NOTES; }
"to_chord"                                  { return TO_CHORD; }
"reproduce_note"                            { return REPRODUCE_NOTE; }
"reproduce_chord"                           { return REPRODUCE_CHORD; }
"is_note"                                   { return IS_NOTE; }
"is_chord"                                  { return IS_CHORD; }

"("											{ return OPEN_PARENTHESIS; }
")"											{ return CLOSE_PARENTHESIS; }
";"                                         { return DELIMITER; }

"note"                                      { return NOTE_TYPE; }
"chord"                                     { return CHORD_TYPE; }
"string"                                    { return STRING_TYPE; }
"integer"                                   { return INTEGER_TYPE; }

{chord}                                     { return ChordPatternAction(yytext);}
{note}                                      { return NotePatternAction(yytext);}
{integer}									{ return IntegerPatternAction(yytext); }
{string}                                    { return StringPatternAction(yytext); }
{whitespace}								{ IgnoredPatternAction(yytext); }
{variable_name}                             { return VariableNamePatternAction(yytext); }
.											{ return UnknownPatternAction(yytext); }

%%
