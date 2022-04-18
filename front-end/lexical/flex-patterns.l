%{
    #include "flex-actions.h"
%}

%option nodefault
%option noyywrap
%option yylineno


WHITESPACE          [ \f\n\r\t\v]
VARIABLE 	        [a-zA-Z]+[_0-9A-Za-z]*
STRING 		        ["][^\n\r]*["]
INTEGER 	        [-]?[0-9]+
CHORD               [A-G]
NOTE                [do|re|mi|fa|sol|la|si][#]?

%%

"is"                                {return ASSIGN;}
"plus"                              {return PLUS;}
"minus"                             {return MINUS;}     
"times"                             {return MULTIPLY;}
"by"                                {return DIVIDE;}
"bigger than"                       {return GREATER;}
"lesser than"                       {return LOWER;}
"same as"                           {return EQUALS;}
"not same as"                       {return NOT_EQUALS;}
"and"                               {return AND;}
"or"                                {return OR;}
"not"                               {return NOT;}
"true"                              {return TRUE;}
"false"                             {return FALSE;}
"if"                                {return IF;}
"then"                              {return THEN;}
"else if"                           {return ELSE;}
"end if"                            {return END_IF;}
"do:"                               {return DO;}
"while"                             {return WHILE;}
"("                                 {return OPEN_PARENTHESIS;}
")"                                 {return CLOSE_PARENTHESIS;}
"print"                             {return PRINT;}
"line"                              {return NEW_LINE;}
{NOTE}                              {return MUSICAL_NOTE;}
{CHORD}                             {return MUSICAL_CHORD;}
"to notes"                          {return TO_NOTES;}
"to chord"                          {return TO_CHORD;}
"concat notes"                      {return CONCAT_NOTES;}
"reproduce chord"                   {return REPRODUCE_CHORD;}
"reproduce note"                    {return REPRODUCE_NOTE;}
{INTEGER}                           {return IntegerPatternAction(yytext);}
{STRING}                            {return StringPatternAction(yytext);}
.									{return UnknownPatternAction(yytext);}
%%