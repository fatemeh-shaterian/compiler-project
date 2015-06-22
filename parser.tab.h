/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EQUAL = 258,
    NOT_EQUAL = 259,
    LESS_OR_EQUAL = 260,
    LESS_THAN = 261,
    BIGGER_THAN = 262,
    BIGGER_OR_EQUAL = 263,
    ASSIGNMENT = 264,
    NOT = 265,
    ARITHMATIC_AND = 266,
    LOGICAL_AND = 267,
    ARITHMATIC_OR = 268,
    LOGICAL_OR = 269,
    LOGICAL_OR_ARITHMATIC_XOR = 270,
    PRODUCTION = 271,
    ADD = 272,
    INCREMENT = 273,
    DECREMENT = 274,
    SUB_AND_UNARY_MINUS = 275,
    DIV = 276,
    MOD = 277,
    OPENING_CURLY_BRACE = 278,
    CLOSING_CURLY_BRACE = 279,
    OPENING_PARENTHESIS = 280,
    CLOSING_PARENTHESIS = 281,
    DOT = 282,
    COMMA = 283,
    COLON = 284,
    SEMI_COLON = 285,
    OPENING_BRACE = 286,
    CLOSING_BRACE = 287,
    BOOLEAN_CONST = 288,
    INTEGER_CONST = 289,
    LONG_CONST = 290,
    REAL_CONST = 291,
    CHARACTER_CONST = 292,
    STRING_CONST = 293,
    ID = 294,
    AUTO = 295,
    BOOL = 296,
    BREAK = 297,
    CASE = 298,
    CHAR = 299,
    CLASS = 300,
    CONST = 301,
    CONTINUE = 302,
    DEFAULT = 303,
    DESTRUCT = 304,
    DOUBLE = 305,
    ELSE = 306,
    FLOAT = 307,
    FOR = 308,
    FOREACH = 309,
    GOTO = 310,
    IF = 311,
    IN = 312,
    INT = 313,
    LONG = 314,
    NEW = 315,
    PRIVATE = 316,
    PROCEDURE = 317,
    PUBLIC = 318,
    REPEAT = 319,
    RETURN = 320,
    SIZEOF = 321,
    STATIC = 322,
    STRING = 323,
    SWITCH = 324,
    UNTIL = 325,
    VOID = 326,
    INHERITS = 327,
    OF = 328,
    EXPR = 329,
    UNARY_MINUS = 330,
    LOWER_THAN_ELSE = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "Parser.y" /* yacc.c:1909  */

  int			int_val;
  long 			long_val;
  const char*	string_val;
  bool 			bool_val;
  double		real_val;
  char			char_val;
  const char*        id_name ;

#line 141 "Parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
