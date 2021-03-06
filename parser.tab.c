/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

	#include <iostream>
	#include <cstdio>
	#include "CG.h"
	#include <stack>
	using namespace std;
	int yyerror(const char *s);	
	int yylex();
	int yyparse();
	
	
	string assigned;	
	stack <string> kindst;
	cg cgr;
	
        

#line 84 "Parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.tab.h".  */
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
#line 19 "Parser.y" /* yacc.c:355  */

  int			int_val;
  long 			long_val;
  const char*	string_val;
  bool 			bool_val;
  double		real_val;
  char			char_val;
  const char*        id_name ;

#line 211 "Parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "Parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   119,   121,   122,   124,   125,   126,   128,
     129,   131,   132,   134,   135,   137,   138,   139,   141,   142,
     144,   145,   147,   148,   150,   151,   153,   154,   156,   157,
     159,   160,   162,   162,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   175,   175,   176,   176,   178,   179,
     181,   182,   184,   186,   187,   188,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   203,   203,
     204,   204,   206,   207,   208,   210,   211,   213,   214,   214,
     215,   218,   219,   220,   222,   222,   222,   224,   224,   224,
     225,   225,   225,   226,   228,   229,   231,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   258,   259,   261,   262,   263,   264,   266,   267,   270,
     271,   272,   273,   274,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUAL", "NOT_EQUAL", "LESS_OR_EQUAL",
  "LESS_THAN", "BIGGER_THAN", "BIGGER_OR_EQUAL", "ASSIGNMENT", "NOT",
  "ARITHMATIC_AND", "LOGICAL_AND", "ARITHMATIC_OR", "LOGICAL_OR",
  "LOGICAL_OR_ARITHMATIC_XOR", "PRODUCTION", "ADD", "INCREMENT",
  "DECREMENT", "SUB_AND_UNARY_MINUS", "DIV", "MOD", "OPENING_CURLY_BRACE",
  "CLOSING_CURLY_BRACE", "OPENING_PARENTHESIS", "CLOSING_PARENTHESIS",
  "DOT", "COMMA", "COLON", "SEMI_COLON", "OPENING_BRACE", "CLOSING_BRACE",
  "BOOLEAN_CONST", "INTEGER_CONST", "LONG_CONST", "REAL_CONST",
  "CHARACTER_CONST", "STRING_CONST", "ID", "AUTO", "BOOL", "BREAK", "CASE",
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DESTRUCT", "DOUBLE",
  "ELSE", "FLOAT", "FOR", "FOREACH", "GOTO", "IF", "IN", "INT", "LONG",
  "NEW", "PRIVATE", "PROCEDURE", "PUBLIC", "REPEAT", "RETURN", "SIZEOF",
  "STATIC", "STRING", "SWITCH", "UNTIL", "VOID", "INHERITS", "OF", "EXPR",
  "UNARY_MINUS", "LOWER_THAN_ELSE", "$accept", "program_start", "$@1",
  "program", "program_parts", "class_def_decleration", "class_dcl",
  "polymorphic_opt", "class_body", "spec_on_class", "func_proc",
  "func_dcl", "argument", "arguments", "array_dcl", "proc_dcl",
  "access_level", "type", "var_dcl", "$@2", "$@3", "var_dcl_cnts",
  "var_dcl_cnt", "block", "run_content", "statement", "assignment", "$@4",
  "$@5", "method_call", "parameters", "cond_stmt", "$@6",
  "closing_paranthes", "cases", "loop_stmt", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "expr_assign", "goto", "label", "expr", "unary_op",
  "variable", "array_use", "const_val", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -134,    41,    64,  -134,  -134,  -134,  -134,  -134,    12,   212,
    -134,  -134,  -134,  -134,    16,  -134,  -134,  -134,    64,  -134,
    -134,  -134,  -134,  -134,    19,  -134,   -19,  -134,    39,  -134,
      59,    26,   -51,  -134,    37,    63,    26,   212,   212,    15,
      58,    68,  -134,    83,  -134,  -134,    74,    90,    30,    62,
     -51,    69,  -134,    80,    72,    81,    26,   311,    88,  -134,
      26,    57,    89,   -51,   -51,  -134,    93,    94,  -134,   -15,
      96,    -3,  -134,   311,  -134,  -134,   311,   311,  -134,  -134,
    -134,  -134,  -134,  -134,    60,  -134,   281,    26,    25,  -134,
      26,  -134,   311,    65,  -134,  -134,  -134,    52,    98,   179,
    -134,  -134,   101,   109,  -134,  -134,  -134,  -134,   388,   -17,
      99,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   108,  -134,  -134,
    -134,   436,  -134,  -134,  -134,    -8,   111,   113,    96,   119,
     121,   115,   122,  -134,   289,   127,   130,  -134,   179,   132,
     179,   129,  -134,  -134,   134,  -134,   348,    31,    96,   212,
    -134,  -134,   136,   137,  -134,   252,   252,    40,    40,    40,
      40,   536,   476,   496,   456,   516,  -134,    73,    73,  -134,
    -134,  -134,  -134,  -134,  -134,   128,    90,   135,  -134,   311,
     143,  -134,   368,   212,   138,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,    26,   139,  -134,   141,   103,   412,
     105,  -134,   142,   150,  -134,  -134,   311,   311,   140,  -134,
     143,   153,   152,   110,   436,   436,   159,   144,   311,  -134,
     161,   162,   166,   143,  -134,   436,   177,   311,   311,  -134,
     143,   175,   160,   176,   436,   180,  -134,   178,   171,   163,
     143,   143,  -134,   181,   193,  -134,  -134,   143,   143,   160,
     185,  -134,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    40,    43,    35,    38,     0,     0,
      39,    36,    34,    37,     0,    41,    42,     3,     4,     6,
      10,     7,    20,    21,     0,     8,     0,    44,     0,     5,
       0,     0,    15,     9,     0,     0,     0,    26,    26,   123,
       0,    48,    51,    50,    33,    32,     0,     0,    18,     0,
      15,     0,    27,     0,     0,     0,     0,     0,   125,    47,
       0,    68,     0,    15,    15,    19,    14,     0,    45,     0,
      28,     0,   124,     0,   121,   122,     0,     0,   132,   129,
     134,   130,   131,   133,   123,   117,     0,     0,   116,   118,
       0,    49,     0,     0,    12,    17,    16,     0,     0,    53,
      30,    31,     0,    24,    22,    23,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   114,   115,
     126,    69,    71,    13,    11,   123,     0,     0,    28,     0,
       0,     0,     0,    90,     0,     0,     0,    46,    53,     0,
      53,     0,    58,    59,     0,    63,     0,   116,    28,     0,
     113,    73,     0,    75,    74,   107,   108,   111,   112,   110,
     109,   103,   102,   104,   105,   106,    99,    97,    98,   100,
     101,   127,    96,    64,    65,     0,    87,     0,    95,     0,
       0,    60,     0,     0,     0,    54,    52,    55,    56,    62,
      57,    29,    25,    72,     0,     0,    84,     0,     0,     0,
       0,    61,     0,     0,    76,    66,     0,     0,     0,    81,
       0,     0,     0,     0,    85,    88,     0,    77,     0,    67,
       0,     0,     0,     0,    78,    91,     0,     0,     0,    93,
       0,     0,    82,     0,    94,     0,    79,     0,     0,     0,
       0,     0,    92,     0,     0,    86,    89,     0,     0,    82,
       0,    83,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,   206,  -134,  -134,  -134,   133,   -26,  -134,
    -134,   189,    82,   201,  -133,  -134,  -134,    -2,     0,  -134,
    -134,   -30,  -134,   -70,  -122,  -134,   -96,  -134,  -134,   117,
      36,  -134,  -134,  -134,   -13,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,     4,  -134,  -134,   -44,   -74,     3,   148,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    17,    18,    19,    20,    35,    46,    47,
      21,    22,    52,    53,   103,    23,    48,   147,   148,    36,
      31,    40,    41,   101,   149,   150,    42,    92,    93,    85,
     162,   152,   240,   220,   249,   153,   216,   231,   207,   232,
     190,   241,   243,   154,   155,   156,    87,    88,    58,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   105,    25,   151,    32,   185,    51,    27,    99,   161,
      44,    33,    45,    86,   129,   100,    24,   109,    25,   110,
      99,   182,    39,    57,    67,   201,   195,   104,   197,   106,
      91,   -40,   107,   108,    43,    54,    54,    95,    96,    43,
      61,     3,    56,    74,    75,    24,    57,    64,   131,    74,
      75,    26,   151,    34,   151,    28,   122,   123,    30,    72,
     124,   125,   126,    43,    37,    39,    49,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   129,    38,   109,    50,   110,    59,   122,
     128,    57,    61,   130,   125,   126,    60,    65,    62,    68,
     192,    66,   157,     4,     5,     6,    69,    71,     7,     8,
       9,    70,   163,    72,    10,    90,    11,   -70,    98,    94,
     210,    97,    12,    13,    34,   132,    14,   102,   134,     4,
       5,     6,    15,   158,     7,    16,     9,   159,    84,    57,
      10,   183,    11,   184,   186,   209,   187,   189,    12,    13,
     227,   157,   193,   157,   188,   194,   196,    54,    15,   198,
     218,    16,   203,   239,   199,   204,    99,   205,   222,   215,
     246,   217,   224,   225,   208,   221,   223,   213,   228,   226,
     255,   256,   229,   230,   235,   233,   206,   259,   260,    73,
     236,   212,   237,   244,   244,   234,   238,    74,    75,    76,
     242,   247,   250,   248,    77,   253,   251,   163,   252,   262,
     257,   254,    78,    79,    80,    81,    82,    83,   135,     5,
       6,   136,   258,     7,    29,     9,   137,   164,   138,    10,
     133,    11,   139,   140,   141,   142,    63,    12,    13,    55,
     214,   202,   245,   143,   144,   145,   261,    15,   146,     0,
      16,     4,     5,     6,     0,     0,     7,   113,   114,   115,
     116,     0,    10,     0,    11,     0,     0,     0,   122,   123,
      12,    13,   124,   125,   126,   181,     0,     0,     0,     0,
      15,     0,     0,    16,   111,   112,   113,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,    73,
       0,   124,   125,   126,     0,     0,     0,    74,    75,    76,
       0,     0,     0,   127,    77,     0,     0,     0,     0,   191,
       0,    73,    78,    79,    80,    81,    82,    83,    84,    74,
      75,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,   111,   112,   113,   114,   115,   116,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,   124,   125,
     126,   111,   112,   113,   114,   115,   116,     0,   200,   117,
     118,   119,   120,   121,   122,   123,     0,     0,   124,   125,
     126,   111,   112,   113,   114,   115,   116,     0,   211,   117,
     118,   119,   120,   121,   122,   123,     0,     0,   124,   125,
     126,     0,     0,     0,   160,   111,   112,   113,   114,   115,
     116,     0,     0,   117,   118,   119,   120,   121,   122,   123,
       0,     0,   124,   125,   126,     0,     0,     0,   219,   111,
     112,   113,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,     0,   124,   125,   126,   111,
     112,   113,   114,   115,   116,     0,     0,   117,   118,   119,
       0,   121,   122,   123,     0,     0,   124,   125,   126,   111,
     112,   113,   114,   115,   116,     0,     0,   117,     0,   119,
       0,   121,   122,   123,     0,     0,   124,   125,   126,   111,
     112,   113,   114,   115,   116,     0,     0,   117,     0,     0,
       0,   121,   122,   123,     0,     0,   124,   125,   126,   111,
     112,   113,   114,   115,   116,     0,     0,   117,     0,     0,
       0,     0,   122,   123,     0,     0,   124,   125,   126,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,   122,   123,     0,     0,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
       2,    71,     2,    99,    23,   138,    36,     9,    23,    26,
      61,    30,    63,    57,    88,    30,    18,    25,    18,    27,
      23,    29,    39,    31,    50,   158,   148,    30,   150,    73,
      60,    39,    76,    77,    31,    37,    38,    63,    64,    36,
       9,     0,    27,    18,    19,    47,    31,    47,    92,    18,
      19,    39,   148,    72,   150,    39,    16,    17,    39,    56,
      20,    21,    22,    60,    25,    39,    29,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   157,    25,    25,    23,    27,    30,    16,
      87,    31,     9,    90,    21,    22,    28,    67,    24,    30,
     144,    39,    99,    39,    40,    41,    26,    26,    44,    45,
      46,    39,   109,   110,    50,    27,    52,    60,    24,    30,
     190,    28,    58,    59,    72,    60,    62,    31,    30,    39,
      40,    41,    68,    32,    44,    71,    46,    28,    39,    31,
      50,    30,    52,    30,    25,   189,    25,    25,    58,    59,
     220,   148,    25,   150,    39,    25,    24,   159,    68,    30,
      57,    71,    26,   233,    30,    28,    23,    39,    26,    30,
     240,    30,   216,   217,    39,    70,    26,    39,    25,    39,
     250,   251,    30,    73,   228,    26,   186,   257,   258,    10,
      29,   193,    30,   237,   238,    51,    30,    18,    19,    20,
      23,    26,    26,    43,    25,    34,    26,   204,    30,    24,
      29,    48,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    44,    18,    46,    47,   110,    49,    50,
      97,    52,    53,    54,    55,    56,    47,    58,    59,    38,
     204,   159,   238,    64,    65,    66,   259,    68,    69,    -1,
      71,    39,    40,    41,    -1,    -1,    44,     5,     6,     7,
       8,    -1,    50,    -1,    52,    -1,    -1,    -1,    16,    17,
      58,    59,    20,    21,    22,   127,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    10,
      -1,    20,    21,    22,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    32,    25,    -1,    -1,    -1,    -1,    30,
      -1,    10,    33,    34,    35,    36,    37,    38,    39,    18,
      19,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      22,     3,     4,     5,     6,     7,     8,    -1,    30,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      22,     3,     4,     5,     6,     7,     8,    -1,    30,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    26,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    22,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    -1,    -1,    20,    21,    22,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    -1,    13,
      -1,    15,    16,    17,    -1,    -1,    20,    21,    22,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    20,    21,    22,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    20,    21,    22,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,    79,     0,    39,    40,    41,    44,    45,    46,
      50,    52,    58,    59,    62,    68,    71,    80,    81,    82,
      83,    87,    88,    92,    94,    95,    39,    94,    39,    80,
      39,    97,    23,    30,    72,    84,    96,    25,    25,    39,
      98,    99,   103,   124,    61,    63,    85,    86,    93,    29,
      23,    98,    89,    90,    94,    90,    27,    31,   125,    30,
      28,     9,    24,    88,    95,    67,    39,    85,    30,    26,
      39,    26,   124,    10,    18,    19,    20,    25,    33,    34,
      35,    36,    37,    38,    39,   106,   122,   123,   124,   126,
      27,    98,   104,   105,    30,    85,    85,    28,    24,    23,
      30,   100,    31,    91,    30,   100,   122,   122,   122,    25,
      27,     3,     4,     5,     6,     7,     8,    11,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    32,   124,   123,
     124,   122,    60,    84,    30,    39,    42,    47,    49,    53,
      54,    55,    56,    64,    65,    66,    69,    94,    95,   101,
     102,   103,   108,   112,   120,   121,   122,   124,    32,    28,
      26,    26,   107,   124,   106,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   125,    29,    30,    30,    91,    25,    25,    39,    25,
     117,    30,   122,    25,    25,   101,    24,   101,    30,    30,
      30,    91,    89,    26,    28,    39,    95,   115,    39,   122,
     100,    30,    94,    39,   107,    30,   113,    30,    57,    26,
     110,    70,    26,    26,   122,   122,    39,   100,    25,    30,
      73,   114,   116,    26,    51,   122,    29,    30,    30,   100,
     109,   118,    23,   119,   122,   119,   100,    26,    43,   111,
      26,    26,    30,    34,    48,   100,   100,    29,    29,   100,
     100,   111,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    79,    78,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    96,    95,    97,    95,    98,    98,
      99,    99,   100,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   104,   103,
     105,   103,   106,   106,   106,   107,   107,   108,   109,   108,
     108,   110,   111,   111,   113,   114,   112,   115,   116,   112,
     117,   118,   112,   112,   119,   120,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   126,   126,   126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     3,
       1,     7,     6,     5,     3,     0,     3,     3,     1,     2,
       1,     1,     6,     6,     3,     5,     0,     1,     0,     3,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     4,     1,     3,
       1,     1,     3,     0,     2,     2,     2,     2,     1,     1,
       2,     3,     2,     1,     2,     2,     4,     5,     0,     4,
       0,     4,     4,     3,     3,     1,     3,     5,     0,     8,
      12,     1,     0,     5,     0,     0,    10,     0,     0,    10,
       0,     0,     9,     7,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     3,     2,     4,     4,     3,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 119 "Parser.y" /* yacc.c:1646  */
    {kindst.push("@"); cgr.init();}
#line 1562 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 119 "Parser.y" /* yacc.c:1646  */
    {cgr.printdata(); cgr.printcode(); cout<<"yes"<<endl; }
#line 1568 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 164 "Parser.y" /* yacc.c:1646  */
    {kindst.push("int");}
#line 1574 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 165 "Parser.y" /* yacc.c:1646  */
    {kindst.push("bool");}
#line 1580 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 166 "Parser.y" /* yacc.c:1646  */
    {kindst.push("float");}
#line 1586 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 167 "Parser.y" /* yacc.c:1646  */
    {kindst.push("long");}
#line 1592 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "Parser.y" /* yacc.c:1646  */
    {kindst.push("char");}
#line 1598 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 169 "Parser.y" /* yacc.c:1646  */
    {kindst.push("double");}
#line 1604 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 171 "Parser.y" /* yacc.c:1646  */
    {kindst.push("string");}
#line 1610 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "Parser.y" /* yacc.c:1646  */
    {kindst.push("auto");}
#line 1616 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 175 "Parser.y" /* yacc.c:1646  */
    {cgr.flip();}
#line 1622 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 175 "Parser.y" /* yacc.c:1646  */
    {kindst.pop(); }
#line 1628 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 176 "Parser.y" /* yacc.c:1646  */
    {cgr.flip();}
#line 1634 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 176 "Parser.y" /* yacc.c:1646  */
    {kindst.pop();}
#line 1640 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 181 "Parser.y" /* yacc.c:1646  */
    {cgr.flip();}
#line 1646 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 203 "Parser.y" /* yacc.c:1646  */
    {cgr.removeTrash(); assigned=cgr.lastFind; cgr.flip();}
#line 1652 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 203 "Parser.y" /* yacc.c:1646  */
    {cgr.assign(assigned);}
#line 1658 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 204 "Parser.y" /* yacc.c:1646  */
    {cgr.flip();}
#line 1664 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 213 "Parser.y" /* yacc.c:1646  */
    {cgr.endofIf();}
#line 1670 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 214 "Parser.y" /* yacc.c:1646  */
    {cgr.elseblock();}
#line 1676 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 214 "Parser.y" /* yacc.c:1646  */
    {cgr.endofelse();}
#line 1682 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 218 "Parser.y" /* yacc.c:1646  */
    {cgr.ifblock();}
#line 1688 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 222 "Parser.y" /* yacc.c:1646  */
    {cgr.addforlabel();}
#line 1694 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 222 "Parser.y" /* yacc.c:1646  */
    {cgr.checkbe();}
#line 1700 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 223 "Parser.y" /* yacc.c:1646  */
    {cgr.settingout();}
#line 1706 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 224 "Parser.y" /* yacc.c:1646  */
    {cgr.addforlabel();}
#line 1712 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 224 "Parser.y" /* yacc.c:1646  */
    {cgr.checkbe();}
#line 1718 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 224 "Parser.y" /* yacc.c:1646  */
    {cgr.settingout();}
#line 1724 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 225 "Parser.y" /* yacc.c:1646  */
    {cgr.addforlabel();}
#line 1730 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 225 "Parser.y" /* yacc.c:1646  */
    {cgr.checkbe();}
#line 1736 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 229 "Parser.y" /* yacc.c:1646  */
    {cgr.addgoto((yyvsp[0].id_name));}
#line 1742 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 231 "Parser.y" /* yacc.c:1646  */
    {cgr.label((yyvsp[-1].id_name));}
#line 1748 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 233 "Parser.y" /* yacc.c:1646  */
    {cgr.add();}
#line 1754 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 234 "Parser.y" /* yacc.c:1646  */
    {cgr.sub();}
#line 1760 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 235 "Parser.y" /* yacc.c:1646  */
    {cgr.mul();}
#line 1766 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 236 "Parser.y" /* yacc.c:1646  */
    {cgr.div();}
#line 1772 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 237 "Parser.y" /* yacc.c:1646  */
    {cgr.mod();}
#line 1778 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 238 "Parser.y" /* yacc.c:1646  */
    {cgr.logicaland();}
#line 1784 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 239 "Parser.y" /* yacc.c:1646  */
    {cgr.arithand();}
#line 1790 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 240 "Parser.y" /* yacc.c:1646  */
    {cgr.arithor();}
#line 1796 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 241 "Parser.y" /* yacc.c:1646  */
    {cgr.logicalor();}
#line 1802 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 242 "Parser.y" /* yacc.c:1646  */
    {cgr.logorarithxor();}
#line 1808 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 243 "Parser.y" /* yacc.c:1646  */
    {cgr.equal();}
#line 1814 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 244 "Parser.y" /* yacc.c:1646  */
    {cgr.notequal();}
#line 1820 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 245 "Parser.y" /* yacc.c:1646  */
    {cgr.bigorequ();}
#line 1826 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 246 "Parser.y" /* yacc.c:1646  */
    {cgr.bigthan();}
#line 1832 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 247 "Parser.y" /* yacc.c:1646  */
    {cgr.lessorequ();}
#line 1838 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 248 "Parser.y" /* yacc.c:1646  */
    {cgr.lessthan();}
#line 1844 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 256 "Parser.y" /* yacc.c:1646  */
    {cgr.neg();}
#line 1850 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 261 "Parser.y" /* yacc.c:1646  */
    {cgr.addinst((yyvsp[0].id_name),kindst.top()); cgr.push((yyvsp[0].id_name));}
#line 1856 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 270 "Parser.y" /* yacc.c:1646  */
    {cgr.push((yyvsp[0].int_val));}
#line 1862 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 273 "Parser.y" /* yacc.c:1646  */
    {cgr.push((yyvsp[0].bool_val));}
#line 1868 "Parser.tab.c" /* yacc.c:1646  */
    break;


#line 1872 "Parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 278 "Parser.y" /* yacc.c:1906  */
