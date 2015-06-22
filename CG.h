#ifndef __CODE__CG
#define __CODE__CG
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class cg
{
public:
	ofstream fout;
	string lastFind;
        bool indcl;
        
        
	void init();
	void push(int);
	void push(const char*);
	void push(bool);
	void add();
	void mul();	
	void mod();
	void logicaland();
	void sub();
	void div();
	void neg();
	void arithand();
	void arithor();
	void logicalor();
	void logorarithxor();
	void equal();
	void notequal();
	void bigorequ();
	void bigthan();
	void lessorequ();
	void lessthan();
	void printcode();
	string itos(int);
	bool isDeclaredBefor(string);
	void assign(string);
	void flip();
	string makename(const char*);
	void removeTrash();
	void addinst(const char*,string);
	////////////////////////////////////////if///////////////////
	void ifblock();
	void elseblock();
	void endofIf();
	void endofelse();
	///////////////////////////////////////////////////////////
	
	void addgoto(const char* i);
	void label(const char* i);
	void printdata();
	
	void addforlabel();
	void checkbe();
	void settingout();
	
};
#endif
