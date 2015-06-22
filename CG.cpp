#include "CG.h"
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stack>
#include <stdlib.h>
struct arraydscp
{
        string type;
};
struct symtab
{
        string name;
        string kind;
        arraydscp* dscpptr;
};
struct textkind
{
        string op;
        string opr1;
        string opr2;
        string opr3;
};
struct datakind 
{
        string name;
        string op1;
        string op2;
        string op3;
        string op4;       
};

	vector <textkind> text;         //.text
	vector <datakind> data;         //.data if array added
	vector<string> withoutarraydata; //.data without arrary
	
	vector<symtab> sttable;         //name, kind ,DSCP
	
	stack <string> labelStack;
	int lablecounter=0;
	string lb1 = "L";
	string lb2;
	string temp;

	bool cg::isDeclaredBefor(string name)
      	{
                for(int i = 0;i<sttable.size();i++){
			if(sttable[i].name==name){
				lastFind=sttable[i].name;				
				return true;
				}
		}
		return false;
                        
      	}


        string cg::makename(const char* strname)
        {
	        char temp;
	        char chr [1280];
	        string strcp = strname;
	        temp=strcp[0];
	        cout<<"strcp"<<strcp<<endl;
	        int i = 0;
	        while((temp != '=')&&(temp!='=')&&(temp!='-')&&(temp!=')')&&(temp!='(')&&(temp!='*')&&(temp!='&')&&(temp!='^')&&(temp!= ' ')&&(temp!='%')&&(temp!='@')&&(temp!='!')&&(temp!='}')&&(temp!='{')&&(temp!='"')&&(temp!=':')&&(temp!=';')&&(temp!='?')&&(temp!='>')&&(temp!='<')&&(temp!='|')&&(temp!='>'))
	        {
		        //i++;
		        chr[i] = temp;
		        i++;
		        temp = strcp[i];
		        //cout<<i<<endl;
	        }
	        string strtemp = chr;
	        cout<<strtemp<<endl;
	        //cout<<"$$"<<string(chr)<<endl;
	        return strtemp;
        }

string cg:: itos(int a) 
{
	string sign = a<0?"-":"";
	string result = a>0?string(1,(a%10+'0')):string(1,((a=-a)%10+'0'));
	(a/=10)>0?result=itos(a)+result:result;
	return sign+result;
}

void cg:: init()
{

	indcl=false;
	fout.open("output.asm");

}

////////////////////////////////////////push in run time stack///////////////////////

void cg:: push(int i)
{
        textkind temp;
        temp.op = "mov";
        temp.opr1 = "eax";
        temp.opr2 = itos(i);
        temp.opr3 = "";
        text.push_back(temp);
         textkind temp2;
         temp2.op = "push";
         temp2.opr1 = "eax";
         temp2.opr2 = "";
        temp2.opr3 = "";
         text.push_back(temp2);
	//fout << "mov" << " eax"<< ","<<i << endl;
        //	fout<<"push eax"<<endl;
}

void cg:: push(bool i)
{	
	string boolVal ="0";
	if(i)
		boolVal = "1";
	textkind temp1;
        temp1.op = "mov";
        temp1.opr1 = "eax";
        temp1.opr2 = boolVal;
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"mov eax,"<<boolVal<<endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
        temp1.opr2 = "";
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"push eax"<<endl;
	
}

void cg:: push(const char* i)
{
        string str = makename(i);
        textkind temp1;
        temp1.op = "mov";
        temp1.opr1 = "eax";
       	temp1.opr2 = "["+str+"]";
        temp1.opr3 = "";
        text.push_back(temp1);
        //fout << "mov" << " eax"<< ",["<<str<<"]"<< endl;
        temp1.op = "push";
        temp1.opr1 = "eax";
        temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	
	//fout<<"push eax"<<endl;
}
//////////////////////////////////////////////////////////////////////

void cg::addinst(const char* name,string type)
{
	string str=makename(name);
	bool temp = isDeclaredBefor(str);
	if(temp==true)
	{

		if(indcl==true)//declared again ERROR
		{
			fout<<"redeclared"; 
			exit(-1);
		}	
		//if(indcl==false) ---->do nothing
	}
	else
	{
		if (indcl==true) 
		{	
			symtab st;
			st.name=str;
			st.kind=type;
			st.dscpptr=NULL;
			sttable.push_back(st);
			lastFind=str;
			withoutarraydata.push_back(str);
				
			//datakind datatemp;
			//datatemp.name = str;
			//datatemp.op1 = " : dw";
			//datatemp.op2 = "0";
			//datatemp.op3 = "";
			//datatemp.op4 = "";
			//data.push_back(datatemp);
		}			
		
		else 
		{
		        fout<<"redeclared "<<str<<endl;exit(-1);//error
		} 
        }
}

void cg::flip()
{
	indcl=!indcl;
}


////////////////////////////////arithmatic opt/////////////////////

void cg:: add()
{
        textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "add";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "add" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	
}

void cg:: mul()
{
        textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "mul";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "mul" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;		
}

void cg::sub()
{
       textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "sub";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "sub" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	
}

void cg::div()
{
        textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "div";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "div" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	
}

void cg::mod()
{
         textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "mod";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "mod" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	
}

void cg::neg()
{
         textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "neg";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "neg eax"<< endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	
	      
}
void cg::arithand()
{
         textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "and";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "and eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"push eax"<<endl;	

}

void cg::arithor()
{
         textkind temp1;
        temp1.op = "pop";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "or";
        temp1.opr1 = "eax";
         temp1.opr2 = "ebx";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "or" << " eax, ebx" << endl;
	 temp1.op = "push";
        temp1.opr1 = "eax";
         temp1.opr2 = "";
        temp1.opr3 = "";
        text.push_back(temp1);

        //fout<<"pop eax"<<endl;
	//fout<<"pop ebx"<<endl;
	//fout<<"or eax,ebx"<<endl;
	//fout<<"push eax"<<endl;  
}

/////////////////////////////////////////////////logic////////////////////////

void cg::logicalor()
{
        textkind temp1;
       	 temp1.op = "pop";
         temp1.opr1 = "eax";
         temp1.opr2 = "";
         temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "mov";
        temp1.opr1 = "ecx";
         temp1.opr2 = "1";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "mov ecx,1" << endl;
	 temp1.op = "cmp";
	temp1.opr1 = "eax";
        text.push_back(temp1);
	//fout<<"cmp eax,1"<<endl;
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op = "jz";
        temp1.opr1 = lb2;
        temp1.opr2 = "";
	text.push_back(temp1);
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	temp1.op = "cmp";
        temp1.opr1 = "ebx";
        temp1.opr2 = "1";
	text.push_back(temp1);
	//fout<<cmp ebx,1"<<endl;
	temp1.op = "jz";
        temp1.opr1 = lb2;
        temp1.opr2 = "";
	text.push_back(temp1);
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	 temp1.op = "mov";
        temp1.opr1 = "ecx";
         temp1.opr2 = "0";
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"mov eax,1"<<endl;
	temp1.op = lb2 + ":" +"\n"+"push";
        temp1.opr1 = "ecx";
         temp1.opr2 = "";
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"L"<<labelcounter<<"_ :\n push ecx"<<endl;
       
	//fout<<"pop eax"<<endl;
	//fout<<"pop ebx"<<endl;
	//fout<<"mov ecx,1"<<endl;
	//fout<<"cmp eax,1"<<endl;     
	//fout<<"jz "<<lb2<<endl;
	//fout<<"cmp ebx,1"<<endl;
	//fout<<"jz "<<lb2<<endl;
	//fout<<"mov ecx,0"<<endl;
	//fout<<lb2<<": \n push ecx"<<endl;
}

void cg::logicaland()
{
         textkind temp1;
       
	 temp1.op = "pop";
         temp1.opr1 = "eax";
         temp1.opr2 = "";
         temp1.opr3 = "";
         text.push_back(temp1);
        //fout<<"pop eax"<<endl;
        temp1.op = "pop";
        temp1.opr1 = "ebx";
        temp1.opr2 = "";
         temp1.opr3 = "";
         text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	 temp1.op = "mov";
        temp1.opr1 = "ecx";
         temp1.opr2 = "0";
        temp1.opr3 = "";
        text.push_back(temp1);
	//fout << "mov ecx,0" << endl;
	 temp1.op = "cmp";
	temp1.opr1 = "eax";
	temp1.opr2 = "0";
         temp1.opr3 = "";
        text.push_back(temp1);
	//fout<<"cmp eax,0"<<endl;
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op = "jz";
        temp1.opr1 = lb2;
        temp1.opr2 = "";
	text.push_back(temp1);
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	temp1.op = "cmp";
        temp1.opr1 = "ebx";
        temp1.opr2 = "1";
         temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<cmp ebx,0"<<endl;
	temp1.op = "jz";
        temp1.opr1 = lb2;
        temp1.opr2 = "";
	temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	 temp1.op = "mov";
        temp1.opr1 = "ecx";
         temp1.opr2 = "1";
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;
	temp1.op = lb2 + ":" +"\n"+"push";
        temp1.opr1 = "ecx";
         temp1.opr2 = "";
        temp1.opr3 = "";
	text.push_back(temp1);
	//fout<<lb2<<" :\n push ecx"<<endl;

        //fout<<"pop eax"<<endl;
	//fout<<"pop ebx"<<endl;
	//fout<<"mov ecx,0"<<endl;
	//fout<<"cmp eax,0"<<endl;
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	//fout<<cmp ebx,0"<<endl;
	//fout<<"jz L"<<labelcounter<<"_"<<endl;
	//fout<<"mov ecx,1"<<endl;
	//fout<<"L"<<labelcounter<<"_ :"<<endl;
	//fout<<"push ecx"<<endl;
}

void cg::equal()
{
	textkind temp1;
	
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;
	
	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;
	
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op="jnz";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jnz "<<lb2<<endl;

	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;
	
	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl;
}

void cg::notequal()
{
    	textkind temp1;	
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;
	
	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;
	
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op="jz";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jnz "<<lb2<<endl;
	
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;
	
	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl;    
}


void cg::bigthan()
{
	textkind temp1;
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;
	
	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;

	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;

	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op="jg";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jg "<<lb2<<endl;

	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;

	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl; 
        
}

void cg::bigorequ()
{

	textkind temp1;
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;

	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;

	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;

	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op="jge";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jge "<<lb2<<endl;

	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;

	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl;     
}

void cg::lessthan()
{

	textkind temp1;
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;

	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;

	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;

	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";

	temp1.op="jl";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jl "<<lb2<<endl;

	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;

	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl;         
}

void cg::lessorequ()
{
	textkind temp1;
	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,1"<<endl;

	temp1.op="pop";
	temp1.opr1="ebx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop ebx"<<endl;

	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="ebx";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,ebx"<<endl;

	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
	temp1.op="jle";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"jle "<<lb2<<endl;

	temp1.op="mov";
	temp1.opr1="ecx";
	temp1.opr2="0";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov ecx,0"<<endl;

	temp1.op=lb2+" :push";
	temp1.opr1="ecx";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);	
	//fout<<lb2<<" : push ecx"<<endl; 
}

/////////////////////////////////////////////////////////////////////////////

void cg::assign(string ass)
{
	textkind temp1;
	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;

	temp1.op="mov";
	temp1.opr1=ass;
	temp1.opr2="eax";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"mov "<<ass<<",eax"<<endl;
}


///////////////////////////////////////////////print///////////////////////////

void cg::printdata()//without array data
{
        cout<<"print data"<<endl;
        	fout << ".section.data\n";
        for(int i = 0;i<withoutarraydata.size();i++)
        {
                fout<<withoutarraydata[i]<<" : dw 0"<<endl;                
        }
}

void cg::printcode()
{
        fout << ".section.text"<<endl;
	fout << ".globl main"<<endl;
	fout << "main:"<<endl;
        for(int i = 0;i<text.size();i++)
         {
                fout<<text[i].op<<" ";
                fout<<text[i].opr1;
                if(text[i].opr2 != "")
                fout<<" ,";
                fout<<text[i].opr2;
                if(text[i].opr3 != "")
                fout<<" ,"<<endl;                
                fout<<text[i].opr3<<endl;                                
         }         
}
//////////////////////////////////////////////////////////////

void cg::removeTrash(){
	
	textkind temp1;
	
	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);

	//fout<< "pop eax"<<endl;
}



////////////////////////////////////////////////////if block/////////////////////////////

void cg::endofIf()
{
	string temp = labelStack.top();
	labelStack.pop();
	textkind temp1;
	temp1.op=temp + ": ";
	temp1.opr1="";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<temp<<" :"<endl;		
}

void cg::elseblock()
{
	string tmp = labelStack.top();
	labelStack.pop();
	textkind temp1;
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";
        //make label		
	temp1.op="jp";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	labelStack.push(lb2);
	//fout<<"jp "<<lb2<<endl;
	temp1.op=tmp + ": ";
	temp1.opr1="";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<temp<<" :"<endl;
}

void cg::endofelse()
{
	string temp = labelStack.top();
	labelStack.pop();
	textkind temp1;
	temp1.op=temp + ": ";
	temp1.opr1="";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<temp<" :"<endl;
}

void cg::ifblock()
{
	temp = itos(lablecounter++);
	lb2= lb1 + temp + "_";	
	textkind temp1;	
	temp1.op="pop";
	temp1.opr1="eax";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"pop eax"<<endl;
	temp1.op="cmp";
	temp1.opr1="eax";
	temp1.opr2="1";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<"cmp eax,1"<<endl;
	temp1.op="jnz";
	temp1.opr1=lb2;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	labelStack.push(lb2);
	//fout<<"jnz "<<lb2<<endl;
}
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////goto///////////////////////
void cg::addgoto(const char* i)
{
	textkind temp1;
	string tmp = i;
	temp1.op="jp";
	temp1.opr1=i;
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<" jp"<<tmp<<endl;
}
void cg::label(const char* i)
{
       textkind temp1;
	string tmp = i;
	temp1.op=i;
	temp1.opr1="";
	temp1.opr2="";
	temp1.opr3="";
	text.push_back(temp1);
	//fout<<temp<<endl;
}
//////////////////////////////////////////////////////////////////////////////////
void cg::logorarithxor()
{
	       
}

void cg::addforlabel ()
	{ 
	        textkind temp1;
	        temp = itos(lablecounter++);
	        lb2 = lb1 + temp + "_";
		        temp1.op=lb2 +" :";
		        temp1.opr1="";
                 	temp1.opr2="";
		        temp1.opr3="";
	         text.push_back(temp1);
	        labelStack.push(lb2);
	}
void cg::checkbe()
	{
	        temp = itos(lablecounter++);
	        lb2 = lb1 + temp + "_";
	          textkind temp1;
	          temp1.op="pop";
	          temp1.opr1="eax";
                 temp1.opr2="";
	         temp1.opr3="";
	         text.push_back(temp1);
	           //fout<<"pop"<<"eax"<<endl;
	         temp1.op="cmp";
	          temp1.opr1="eax";
	         temp1.opr2="0";
	         temp1.opr3="";
	          text.push_back(temp1);
       	        // fout<<"cmp"<<"eax"<<",0"<<endl;
	         temp1.op="je";
	          temp1.opr1=lb2;
                 temp1.opr2="";
	         temp1.opr3="";
                 text.push_back(temp1);
      	         //fout<<"je"<<label<<endl;
	        labelStack.push(lb2);
	}
void cg::settingout()
	{ textkind temp1;
	string etmp = labelStack.top();
	labelStack.pop();
	string ftmp = labelStack.top();
	labelStack.pop();  
	  temp1.op="jp";
	  temp1.opr1=ftmp;
         temp1.opr2="";
	 temp1.opr3="";
         text.push_back(temp1);
	 temp1.op=etmp + " :";
	  temp1.opr1="";
         temp1.opr2="";
	 temp1.opr3="";
	  text.push_back(temp1);
	}
