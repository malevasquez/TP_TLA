/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     START = 258,
     END = 259,
     ASSIGN = 260,
     PLUS = 261,
     MINUS = 262,
     MULTIPLY = 263,
     DIVIDE = 264,
     GREATER = 265,
     LOWER = 266,
     EQUALS = 267,
     NOT_EQUALS = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     TRUE = 272,
     FALSE = 273,
     IF = 274,
     THEN = 275,
     ELSE = 276,
     END_IF = 277,
     DO = 278,
     WHILE = 279,
     OPEN_PARENTHESIS = 280,
     CLOSE_PARENTHESIS = 281,
     PRINT = 282,
     NEW_LINE = 283,
     MUSICAL_NOTE = 284,
     MUSICAL_CHORD = 285,
     TO_NOTES = 286,
     TO_CHORD = 287,
     CONCAT_NOTES = 288,
     REPRODUCE_CHORD = 289,
     REPRODUCE_NOTE = 290,
     DELIMITER = 291,
     INTEGER = 292,
     STRING = 293,
     VARIABLE = 294
   };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define ASSIGN 260
#define PLUS 261
#define MINUS 262
#define MULTIPLY 263
#define DIVIDE 264
#define GREATER 265
#define LOWER 266
#define EQUALS 267
#define NOT_EQUALS 268
#define AND 269
#define OR 270
#define NOT 271
#define TRUE 272
#define FALSE 273
#define IF 274
#define THEN 275
#define ELSE 276
#define END_IF 277
#define DO 278
#define WHILE 279
#define OPEN_PARENTHESIS 280
#define CLOSE_PARENTHESIS 281
#define PRINT 282
#define NEW_LINE 283
#define MUSICAL_NOTE 284
#define MUSICAL_CHORD 285
#define TO_NOTES 286
#define TO_CHORD 287
#define CONCAT_NOTES 288
#define REPRODUCE_CHORD 289
#define REPRODUCE_NOTE 290
#define DELIMITER 291
#define INTEGER 292
#define STRING 293
#define VARIABLE 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

