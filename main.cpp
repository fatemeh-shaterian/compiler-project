#include <iostream>
#include <cstdio>
#include <cstdlib>

extern int yylineno;
extern char* yytext;

using namespace std;
int yyparse();
int yyerror(const char *s);

int main(int argc, char **argv)
{
	while (yyparse());

  return 0;
}

int yyerror(const char *s)
{
  	//printf("error on line: %d on: %s -> \t %s\n",yylineno,yytext,s);
  	printf("no\n");
	exit(1);
	return 0;
}
