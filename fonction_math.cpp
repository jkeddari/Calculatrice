#include "fonction_math.hpp"

#include <iostream>


void Priority::fill_priority(){
	op["n"]=7;
	op["fact"]=6;
	op["^"]=6;
	op["!"]=6;
	op["exp"]=5;
	op["sqrt"]=5;
	op["cos"]=5;
	op["sin"]=5;
	op["tan"]=5;
	op["arccos"]=5;
	op["arcsin"]=5;
	op["arctan"]=5;
	op["log"]=5;
	op["*"]=3;
	op["/"]=3;
	op["+"]=2;
	op["-"]=2;
	op["("]=1;
}


int factoriel(int number)
{
	int resulatfactoriel=1;

	if(number==0)
		return resulatfactoriel=1;

	else if(number>0)
	{
		for(int i=1;i<=number;i++)
		{
			resulatfactoriel=resulatfactoriel * i;

		}
	}
	else{
		throw Erreur(1,"Synthaxe Error",2);
	}
return resulatfactoriel;
}

string exec_calc(string a, string b, string op){
	double x(atof(a.c_str())),y(atof(b.c_str()));
	double result;
	if(op=="+") result=x+y;
	if(op=="/") result=x/y;
	if(op=="*") result=x*y;
	if(op=="-") result=x-y;
	if(op=="^") result=pow(x,y);
	if(op=="exp") result=exp(x);
	if(op=="sin") result=sin(x);
	if(op=="cos") result=cos(x);
	if(op=="tan") result=tan(x);
	if(op=="arcsin") result=asin(x);
	if(op=="arccos") result=acos(x);
	if(op=="arctan") result=atan(x);
	if(op=="sqrt") result=sqrt(x);
	if(op=="log") result=log10(x);
	if(op=="fact") result=factoriel(x);
	if(op=="n") result=-x;

	//if(op=="ln") result=ln(x);

	return to_string(result);
}

bool is_operator(string s){
	if(op_size_1.find(s) != string::npos) return true;
	else if(op_size_2.find(s) != string::npos) return true;
	else if(op_size_3.find(s) != string::npos) return true;
	else if(op_size_4.find(s) != string::npos) return true;
	else if(op_size_5.find(s) != string::npos) return true;
	return false;
}

bool is_operand(string s){
	return (is_operator(s) == false and s!="(" and s!=")");
}