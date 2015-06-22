%{
	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include "tok.h"
	using namespace std;
	int yyerror(const char* s);
%}

%option yylineno
%option noyywrap
%option nounput

/************************ Keywords *******************************/
auto auto
bool bool
break break
case case
char char
class class
const const
continue continue
default_keyword default
destruct destruct
double double
else else
float float
for for
foreach foreach
goto goto
if if
in in
int int
long long
new new
private private
procedure procedure
public public
repeat repeat
return return
sizeof sizeof
static static
string string
switch switch
until until
inherits inherits
void_keyword void
of of

/************************ CONSTANTS ************************/

boolean true|false

l [a-zA-Z]
d [0-9]
id (({l}+{d}*)(_{0,2}({l}|{d})+)*)|(_{1,2}({l}|{d})+(_{0,2}({l}|{d})+)*)

single_line_comment @@.*
multi_line_comment \/@(.|\n)*@\/

integer (0x)?[0-9]+

real [0-9]+\.[0-9]+|[0-9]+\.|\.[0-9]+|[0-9]*[eE][\+\-]?[0-9]

character '(.|\\.)?'

string_const \"([^(\\\")]){0,6000}\"

/*********************** Operators **********************************/
equal \=\=
not_equal \!\=
less_or_equal \<\=
less_than \<
bigger_than \>
bigger_or_equal \>\=
assignment \=
not \!
logical_and \&\&
arithmatic_and \&
logical_or \|\|
arithmatic_or \|
logical_or_arithmatic_xor \^
production \*
increment \+\+
decrement \-\-
add \+
sub_and_unary_minus \-
div \/
mod \%
opening_curly_brace \{
closing_curly_brace \}
opening_parenthesis \(
closing_parenthesis \)
dot \.
comma \,
colon \:
semi_colon \;
opening_brace \[
closing_brace \]
white_space [ \t]
line_feed [\r\n]

default .


%%

 /******************* Commands *******************/

{auto} { return AUTO; }
{bool} { return BOOL; }
{break} { return BREAK; }
{case} { return CASE; }
{char} { return CHAR; }
{class} { return CLASS; }
{const} { return CONST; }
{continue} { return CONTINUE; }
{default_keyword} { return DEFAULT; }
{destruct} { return DESTRUCT; }
{double} { return DOUBLE; }
{else} { return ELSE; }
{float} { return FLOAT; }
{for} { return FOR; }
{foreach} { return FOREACH; }
{goto} { return GOTO; }
{if} { return IF; }
{in} { return IN; }
{int} { return INT; }
{long} { return LONG; }
{new} { return NEW; }
{private} { return PRIVATE; }
{procedure} { return PROCEDURE; }
{public} { return PUBLIC; }
{repeat} { return REPEAT; }
{return} { return RETURN; }
{sizeof} { return SIZEOF; }
{static} { return STATIC; }
{string} { return STRING; }
{switch} { return SWITCH; }
{until} { return UNTIL; }
{void_keyword} { return VOID; }
{inherits} { return INHERITS; }
{of} { return OF; }

{boolean} { yylval.bool_val = strcmp(yytext,"true") == 0 ? true : false; return BOOLEAN_CONST; }
{id} { yylval.id_name = yytext; return ID; }


{single_line_comment} { }
{multi_line_comment} { }


{integer} { yylval.int_val = atoi(yytext); return INTEGER_CONST; }
{real} { yylval.real_val = atof(yytext); return REAL_CONST; }
{character} { return CHARACTER_CONST; } /* It is not working... needs a character parser */
{string_const} { yylval.string_val =  string(yytext).substr(1,strlen(yytext)-2).c_str(); return STRING_CONST; } /* It is not working.. needs a parser for escape characters */

{equal} { return EQUAL; }
{not_equal}  { return NOT_EQUAL; }
{less_or_equal}  { return LESS_OR_EQUAL; } 
{less_than}  { return LESS_THAN; }
{bigger_than}  { return BIGGER_THAN; }
{bigger_or_equal}  { return BIGGER_OR_EQUAL; }
{assignment}  { return ASSIGNMENT; }
{not}  { return NOT; }
{arithmatic_and}  { return ARITHMATIC_AND; }
{logical_and}  { return LOGICAL_AND; }
{arithmatic_or}  { return ARITHMATIC_OR; }
{logical_or}  { return LOGICAL_OR; }
{logical_or_arithmatic_xor}  { return LOGICAL_OR_ARITHMATIC_XOR; }
{production}  { return PRODUCTION; }
{add}  { return ADD; }
{increment}  { return INCREMENT; }
{decrement}  { return DECREMENT; }
{sub_and_unary_minus}  { return SUB_AND_UNARY_MINUS; }
{div}  { return DIV; }
{mod}  { return MOD; }
{opening_curly_brace}  { return OPENING_CURLY_BRACE; }
{closing_curly_brace}  { return CLOSING_CURLY_BRACE; }
{opening_parenthesis}  { return OPENING_PARENTHESIS; }
{closing_parenthesis}  { return CLOSING_PARENTHESIS; }
{dot}  { return DOT; }
{comma}  { return COMMA; }
{colon}  { return COLON; }
{semi_colon}  { return SEMI_COLON; }
{opening_brace}  { return OPENING_BRACE; }
{closing_brace}  { return CLOSING_BRACE; }

{line_feed} {;}
{white_space} {;}

{default} { yyerror("scanner error"); }

<<EOF>> { return 0; }

%%
