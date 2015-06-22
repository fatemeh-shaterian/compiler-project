%{
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
	
        
%}

%union{
  int			int_val;
  long 			long_val;
  const char*	string_val;
  bool 			bool_val;
  double		real_val;
  char			char_val;
  const char*        id_name ;
}

%start program_start
%token EQUAL
%token NOT_EQUAL
%token LESS_OR_EQUAL
%token LESS_THAN
%token BIGGER_THAN
%token BIGGER_OR_EQUAL
%token ASSIGNMENT
%token NOT
%token ARITHMATIC_AND
%token LOGICAL_AND
%token ARITHMATIC_OR
%token LOGICAL_OR
%token LOGICAL_OR_ARITHMATIC_XOR
%token PRODUCTION
%token ADD
%token INCREMENT
%token DECREMENT
%token SUB_AND_UNARY_MINUS
%token DIV
%token MOD
%token OPENING_CURLY_BRACE
%token CLOSING_CURLY_BRACE
%token OPENING_PARENTHESIS
%token CLOSING_PARENTHESIS
%token DOT
%token COMMA
%token COLON
%token SEMI_COLON
%token OPENING_BRACE
%token CLOSING_BRACE
%token <bool_val> BOOLEAN_CONST
%token <int_val> INTEGER_CONST
%token <long_val> LONG_CONST
%token <real_val> REAL_CONST
%token <char_val> CHARACTER_CONST
%token <string_val> STRING_CONST
%token <id_name> ID
%token AUTO
%token BOOL
%token BREAK
%token CASE
%token CHAR
%token CLASS
%token CONST
%token CONTINUE
%token DEFAULT
%token DESTRUCT
%token DOUBLE
%token ELSE
%token FLOAT
%token FOR
%token FOREACH
%token GOTO
%token IF
%token IN
%token INT
%token LONG
%token NEW
%token PRIVATE
%token PROCEDURE
%token PUBLIC
%token REPEAT
%token RETURN
%token SIZEOF
%token STATIC
%token STRING
%token SWITCH
%token UNTIL
%token VOID
%token INHERITS
%token OF
%left EXPR
%left LOGICAL_OR
%left LOGICAL_AND
%left ARITHMATIC_OR 
%left LOGICAL_OR_ARITHMATIC_XOR
%left ARITHMATIC_AND 
%left EQUAL NOT_EQUAL
%left LESS_OR_EQUAL LESS_THAN BIGGER_THAN BIGGER_OR_EQUAL    
%left ADD SUB_AND_UNARY_MINUS
%left PRODUCTION DIV MOD
%left INCREMENT DECREMENT
%right ASSIGNMENT
%nonassoc UNARY_MINUS NOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program_start: {kindst.push("@"); cgr.init();}program {cgr.printdata(); cgr.printcode(); cout<<"yes"<<endl; }
	;
program: program_parts
	| program_parts program
	;
program_parts: class_def_decleration
	| func_proc
	| var_dcl
	;
class_def_decleration: CLASS ID SEMI_COLON
	| class_dcl
	;
class_dcl: CLASS ID polymorphic_opt OPENING_CURLY_BRACE class_body CLOSING_CURLY_BRACE SEMI_COLON
	| CLASS ID OPENING_CURLY_BRACE class_body CLOSING_CURLY_BRACE SEMI_COLON
	;
polymorphic_opt: INHERITS COLON ID COMMA polymorphic_opt
	| INHERITS COLON ID
	;
class_body: %empty
	| spec_on_class var_dcl class_body
	| spec_on_class func_dcl class_body
	;
spec_on_class: access_level 
	| access_level STATIC
	;
func_proc: func_dcl
	| proc_dcl
	;
func_dcl: type ID OPENING_PARENTHESIS arguments CLOSING_PARENTHESIS SEMI_COLON
	| type ID OPENING_PARENTHESIS arguments CLOSING_PARENTHESIS block
	;
argument: type ID array_dcl
	| type ID array_dcl COMMA argument
	;
arguments: %empty
	| argument
	;
array_dcl: %empty
	| OPENING_BRACE CLOSING_BRACE array_dcl
	;
proc_dcl: PROCEDURE ID OPENING_PARENTHESIS arguments CLOSING_PARENTHESIS SEMI_COLON
	| PROCEDURE ID OPENING_PARENTHESIS arguments CLOSING_PARENTHESIS block
	;
access_level: PUBLIC | PRIVATE
	;
type: INT {kindst.push("int");}
	| BOOL {kindst.push("bool");}
 	| FLOAT {kindst.push("float");}
	| LONG {kindst.push("long");}
	| CHAR {kindst.push("char");}
	| DOUBLE {kindst.push("double");}
	| ID
	| STRING {kindst.push("string");}
	| VOID
	| AUTO {kindst.push("auto");}
	;
var_dcl: CONST type {cgr.flip();} var_dcl_cnts SEMI_COLON {kindst.pop(); }
	| type  {cgr.flip();} var_dcl_cnts SEMI_COLON {kindst.pop();}
	;
var_dcl_cnts: var_dcl_cnt
	| var_dcl_cnt COMMA  var_dcl_cnts
	;
var_dcl_cnt: variable {cgr.flip();}
	| assignment
	;
block: OPENING_CURLY_BRACE run_content CLOSING_CURLY_BRACE
	;
run_content: %empty
	| var_dcl run_content
	| statement run_content
	;
statement: assignment SEMI_COLON
	| expr SEMI_COLON
	| cond_stmt
	| loop_stmt
	| RETURN SEMI_COLON
	| RETURN expr SEMI_COLON
	| goto SEMI_COLON
	| label
	| BREAK SEMI_COLON
	| CONTINUE SEMI_COLON
	| DESTRUCT array_dcl ID SEMI_COLON
	| SIZEOF OPENING_PARENTHESIS type CLOSING_PARENTHESIS SEMI_COLON
	;
assignment: variable ASSIGNMENT {cgr.removeTrash(); assigned=cgr.lastFind; cgr.flip();}expr {cgr.assign(assigned);}
	| variable ASSIGNMENT {cgr.flip();}NEW
	;
method_call: ID OPENING_PARENTHESIS parameters CLOSING_PARENTHESIS
	| ID OPENING_PARENTHESIS CLOSING_PARENTHESIS
	| ID DOT method_call
	;
parameters: variable
	| variable COMMA parameters
	;
cond_stmt: IF OPENING_PARENTHESIS expr closing_paranthes block {cgr.endofIf();} %prec LOWER_THAN_ELSE
	| IF OPENING_PARENTHESIS expr closing_paranthes block ELSE {cgr.elseblock();} block		 {cgr.endofelse();}
	| SWITCH OPENING_PARENTHESIS ID CLOSING_PARENTHESIS OF COLON OPENING_CURLY_BRACE cases DEFAULT COLON block CLOSING_CURLY_BRACE
;

closing_paranthes : CLOSING_PARENTHESIS {cgr.ifblock();};
cases:%empty
	| CASE INTEGER_CONST COLON block cases
	;
loop_stmt:FOR OPENING_PARENTHESIS var_dcl  {cgr.addforlabel();} expr{cgr.checkbe();} SEMI_COLON 
	   expr_assign  CLOSING_PARENTHESIS block {cgr.settingout();} 
	| FOR OPENING_PARENTHESIS {cgr.addforlabel();} SEMI_COLON expr {cgr.checkbe();}  SEMI_COLON expr_assign   CLOSING_PARENTHESIS block {cgr.settingout();} 
	| REPEAT {cgr.addforlabel();}block UNTIL OPENING_PARENTHESIS expr{cgr.checkbe();} CLOSING_PARENTHESIS SEMI_COLON
	| FOREACH OPENING_PARENTHESIS ID IN ID CLOSING_PARENTHESIS block
	;
expr_assign: expr
goto: GOTO ID{cgr.addgoto($2);}
	;
label: ID COLON{cgr.label($1);}
	;
expr:	  expr ADD expr {cgr.add();}
        | expr  SUB_AND_UNARY_MINUS expr{cgr.sub();}
        | expr PRODUCTION expr{cgr.mul();}
        | expr  DIV expr{cgr.div();}
        | expr MOD  expr {cgr.mod();}
        | expr  LOGICAL_AND expr{cgr.logicaland();}
        | expr ARITHMATIC_AND  expr{cgr.arithand();}
        | expr ARITHMATIC_OR expr {cgr.arithor();} 
        | expr LOGICAL_OR  expr {cgr.logicalor();}   
        | expr  LOGICAL_OR_ARITHMATIC_XOR expr {cgr.logorarithxor();}
	| expr EQUAL expr {cgr.equal();}
	| expr NOT_EQUAL expr {cgr.notequal();}
	| expr BIGGER_OR_EQUAL expr {cgr.bigorequ();}
	| expr BIGGER_THAN expr {cgr.bigthan();}
	| expr LESS_OR_EQUAL expr {cgr.lessorequ();}
	| expr LESS_THAN expr {cgr.lessthan();}
      	| OPENING_PARENTHESIS expr CLOSING_PARENTHESIS
	| unary_op variable
	| variable unary_op
	| variable
	| method_call
	| const_val
	| NOT expr
	| SUB_AND_UNARY_MINUS expr{cgr.neg();} %prec UNARY_MINUS
	;
unary_op: INCREMENT
	| DECREMENT
	;
variable: ID {cgr.addinst($1,kindst.top()); cgr.push($1);} 
	| ID DOT variable
	| ID array_use
	| ID array_use DOT variable
	;
array_use: OPENING_BRACE expr CLOSING_BRACE array_use 
	| OPENING_BRACE expr CLOSING_BRACE
	;

const_val: INTEGER_CONST{cgr.push($1);}
	| REAL_CONST
	| CHARACTER_CONST
	| BOOLEAN_CONST {cgr.push($1);}
	| STRING_CONST
	| LONG_CONST
	;

%%
