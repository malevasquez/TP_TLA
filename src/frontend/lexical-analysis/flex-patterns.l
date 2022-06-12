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

"start"                                     { return StartPatternAction(yytext); }
"end"                                       { return EndPatternAction(yytext); }
"is"                                        { return AssignPatternAction(yytext); }

"plus"                                      {return PlusPatternAction(yytext);}
"minus"                                     {return MinusPatternAction(yytext);}     
"times"                                     {return MultiplyPatternAction(yytext);}
"by"                                        {return DividePatternAction(yytext);}

"if"                                        { return IfPatternAction(yytext); }
"then"                                      { return ThenPatternAction(yytext); }
"else"                                      { return ElsePatternAction(yytext); }
"end_if"                                    { return EndIfPatternAction(yytext); }

"compute"                                   { return DoStatementPatternAction(yytext); }
"while"                                     { return WhilePatternAction(yytext); }

">"                                         {return GreaterPatternAction(yytext);}
"<"                                         {return LowerPatternAction(yytext);}
"="                                         {return EqualsPatternAction(yytext);}
"!="                                        {return NotEqualsPatternAction(yytext);}
"and"                                       {return AndPatternAction(yytext);}
"or"                                        {return OrPatternAction(yytext);}
"not"                                       {return NotPatternAction(yytext);}
"true"                                      {return TruePatternAction(yytext);}
"false"                                     {return FalsePatternAction(yytext);}

"print"                                     { return PrintPatternAction(yytext); }
"print_to_chords"                           { return PrintToChordsPatternAction(yytext); }
"concat_notes"                              { return ConcatNotesPatternAction(yytext); }
"to_notes"                                  { return ToNotesPatternAction(yytext); }
"to_chord"                                  { return ToChordPatternAction(yytext); }
"reproduce_note"                            { return ReproduceNotePatternAction(yytext); }
"reproduce_chord"                           { return ReproduceChordPatternAction(yytext); }
"is_note"                                   { return IsNotePatternAction(yytext); }
"is_chord"                                  { return IsChordPatternAction(yytext); }

"("											{ return OpenParenthesisPatternAction(yytext); }
")"											{ return CloseParenthesisPatternAction(yytext); }
";"                                         { return DelimiterPatternAction(yytext); }

"note"                                      { return NoteTypePatternAction(yytext); }
"chord"                                     { return ChordTypePatternAction(yytext); }
"string"                                    { return StringTypePatternAction(yytext); }
"integer"                                   { return IntegerTypePatternAction(yytext); }

{chord}                                     { return ChordPatternAction(yytext);}
{note}                                      { return NotePatternAction(yytext);}
{integer}									{ return IntegerPatternAction(yytext); }
{string}                                    { return StringPatternAction(yytext); }
{whitespace}								{ IgnoredPatternAction(yytext); }
{variable_name}                             { return VariableNamePatternAction(yytext); }
.											{ return UnknownPatternAction(yytext); }

%%
