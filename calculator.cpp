#include "calculator.hpp"


Calculator::Calculator(string calcul){
	this->calcul=calcul;
	this->calc_postfix=new list<string>;
	this->bad_input();
	if(this->calcul_ok){
		this->calc_to_postfix();
		/*list<string> cp_calc_postfix=*calc_postfix;
		while(!cp_calc_postfix.empty()){
			cout << cp_calc_postfix.front() << endl;
			cp_calc_postfix.pop_front();
		}
		cout << endl;
		*/
		this->postfix_eval();
		this->erase_zero();
	}
	else{
		this->result="Synthaxe Error";
	}

}

Calculator::~Calculator(){
	delete this->calc_postfix;
}


////////  A C C E S S E U R  /////////////////////////////
string Calculator::getCalcul(){
	return this->calcul;
}

string Calculator::getResult(){
	return this->result;
}
//////////////////////////////////////////////////////////

void Calculator::fill_priority(){
	priority_op["^"]=6;
	priority_op["!"]=6;
	priority_op["exp"]=5;
	priority_op["sqrt"]=5;
	priority_op["cos"]=5;
	priority_op["sin"]=5;
	priority_op["tan"]=5;
	priority_op["arccos"]=5;
	priority_op["arcsin"]=5;
	priority_op["arctan"]=5;
	priority_op["log"]=5;
	priority_op["ln"]=5;
	priority_op["*"]=3;
	priority_op["/"]=3;
	priority_op["+"]=2;
	priority_op["-"]=2;
	priority_op["("]=1;

}


void Calculator::bad_input(){
	bool f_operator=false, f_point=false;
	stack<string> p;


	if(!isdigit(this->calcul.at(0)) and this->calcul.at(0)!='(' and this->calcul.at(0)!='n' and op_size_2.find(this->calcul.substr(0,2)) != string::npos and 
	op_size_3.find(this->calcul.substr(0,3)) != string::npos and op_size_4.find(this->calcul.substr(0,4)) != string::npos
	and op_size_5.find(this->calcul.substr(0,5)) != string::npos ){
		return; //Si on commence par un opérateur c'est faux
	}

	for(unsigned int i=0; i< this->calcul.size();i++){
		if(isdigit(this->calcul.at(i))) {f_operator=false;}
		else if(this->calcul.at(i)=='.') {f_point=true;}
		else if(this->calcul.at(i)=='.' and f_point ) return;
		else if(this->calcul.at(i) == 'n' and i+1 < this->calcul.size() 
		and (isdigit(this->calcul.at(i+1)) or this->calcul.at(i+1)=='(' 
		or op_size_2.find(this->calcul.substr(i,2)) != string::npos 
		or op_size_3.find(this->calcul.substr(i,3)) != string::npos 
		or op_size_4.find(this->calcul.substr(i,4)) != string::npos
		or op_size_5.find(this->calcul.substr(i,5)) != string::npos)){f_operator=false;f_point=false;}

		else if(this->calcul.at(i) == '(') {p.push("(");}
		else if(this->calcul.at(i) == ')') {
			if(p.empty()) return;
			p.pop();
			f_operator=false;
			f_point=false;
		}
		else if(op_size_1.find(this->calcul.at(i)) != string::npos && !f_operator) {f_operator=true;f_point=false;}
		else if(op_size_2.find(this->calcul.substr(i,2)) != string::npos) {i+=1;f_operator=true;f_point=false;}
		else if(op_size_3.find(this->calcul.substr(i,3)) != string::npos) {i+=2;f_operator=true;f_point=false;}
		else if(op_size_4.find(this->calcul.substr(i,4)) != string::npos) {i+=3;f_operator=true;f_point=false;}
		else if(op_size_5.find(this->calcul.substr(i,5)) != string::npos) {i+=4;f_operator=true;f_point=false;}
		else return;


	}
	if(f_operator==true) return; 
	if(!p.empty()) return;
	this->calcul_ok=true;
}

///////////////////////////////////////////////////////////////////////////////

bool Calculator::is_operator(string s){
	if(op_size_1.find(s) != string::npos) return true;
	else if(op_size_2.find(s) != string::npos) return true;
	else if(op_size_3.find(s) != string::npos) return true;
	else if(op_size_4.find(s) != string::npos) return true;
	else if(op_size_5.find(s) != string::npos) return true;
	return false;
}

bool Calculator::is_operand(string s){
	return (is_operator(s) == false and s!="(" and s!=")");
}

///////////////////////////////////////////////////////////////////////////////

list<string> Calculator::split_calc(string s){
	unsigned int i=0;
	string buff;
	list<string> l;


	for(i=0; i<s.size();i++){
		buff.clear();
		if(s.at(i)=='n'){
			buff.push_back('-');
			i++;
		}
		if(i<s.size() and (isdigit(s.at(i)) or s.at(i)=='.')){
			while(i<s.size() and (isdigit(s.at(i)) or s.at(i)=='.')){
				buff.push_back((s.at(i)));
				i++;
			} i--;
		}
		else if(i<s.size() and op_size_2.find(s.substr(i,2)) != string::npos) { buff=s.substr(i,2); i+=1; }
		else if(i<s.size() and op_size_3.find(s.substr(i,3)) != string::npos) { buff=s.substr(i,3); i+=2; }
		else if(i<s.size() and op_size_4.find(s.substr(i,4)) != string::npos) { buff=s.substr(i,4); i+=3; }
		else if(i<s.size() and op_size_5.find(s.substr(i,5)) != string::npos) { buff=s.substr(i,5); i+=4; }
		else if(i<s.size()) buff.push_back(s.at(i));

		l.push_back(buff);
	}

	return l;
}

//////////////////////////////////////////////////////////////////////////////


string Calculator::exec_calc(string a, string b, string op){
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
	//if(op=="ln") result=ln(x);

	return to_string(result);
}

/////////////////////////////////////////////////////////////////////////////

void Calculator::calc_to_postfix(){
	list<string> e;
	stack<string> p;
	string buff;

	e=split_calc(this->calcul);
	while(!e.empty()){
		buff=e.front();
		e.pop_front();
		if(Calculator::is_operand(buff)) this->calc_postfix->push_back(buff);
		else if(buff == "(") p.push(buff);
		else if(buff == ")"){
			while(!p.empty() && p.top()!="("){ 
				this->calc_postfix->push_back(p.top());
				p.pop();
			}
			if(p.empty()) throw Erreur(1,"Synthaxe Error",2); else p.pop();
		}
		else{
			if(op_size_2.find(buff) != string::npos) p.push(buff);
			else if(op_size_3.find(buff) != string::npos) p.push(buff);
			else if(op_size_4.find(buff) != string::npos) p.push(buff);
			else if(op_size_5.find(buff) != string::npos) p.push(buff);
			else{
				while(!p.empty() && p.top()!="(" && priority_op[buff] <= priority_op[p.top()]){
					this->calc_postfix->push_back(p.top());
					p.pop();
				}
				p.push(buff);
			}
		}
	}
	while(!p.empty()){
		this->calc_postfix->push_back(p.top());
		p.pop();

	}
}

void Calculator::postfix_eval(){
	stack<string> operandStack;
	string buff, a,b,r;

	while(!this->calc_postfix->empty()){
		buff=this->calc_postfix->front();
		//cout << buff << endl;
		if(!this->calc_postfix->empty()) this->calc_postfix->pop_front();


		if((Calculator::is_operand(buff))){
			operandStack.push(buff);
			//cout << "operand" << endl;
		}
		else{
			if(op_size_5.find(buff) != string::npos or op_size_4.find(buff) != string::npos 
			or op_size_3.find(buff) != string::npos or op_size_2.find(buff) != string::npos){
				//cout << "fonction" << endl;
				a=operandStack.top(); if(!operandStack.empty()) operandStack.pop();
				r=exec_calc(a,b,buff);
				operandStack.push(r);
			}
			else{
				//cout << "operateur" << endl;
				if(!operandStack.empty()){ b=operandStack.top(); operandStack.pop(); }
				if(!operandStack.empty()){ a=operandStack.top(); operandStack.pop(); }
				//cout << "operateur" << endl;
				r=exec_calc(a,b,buff);
				operandStack.push(r);
			}
		}
		//cout << "Top operand = " << operandStack.top() << endl << endl;
	}
	this->result=operandStack.top();
}

void Calculator::erase_zero(){
	for(unsigned int i=this->result.size()-1; i>0 && this->result.at(i)=='0'; i--){
		this->result.erase(i);
	}
	if(this->result.at(this->result.size()-1)=='.') this->result.erase(this->result.size()-1);



}

