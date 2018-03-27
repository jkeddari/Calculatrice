#include "calculator.hpp"
#include <iostream>
#include <list>
#include <map>

string separe(string *s){
	unsigned int i=0;
	string buff;

	if(s->empty()) return buff;
	if(isdigit(s->at(0)) && s->size()==1){
		buff=s->at(0);
		s->clear();
		return buff;
	}
	if(isdigit(s->at(0))){
		while(isdigit(s->at(i)) &&i<s->size()){
			buff.push_back(s->at(i));
			i++;
		}
		*s=s->substr(i);
	}
	else{
		if(s->substr(0,3) == "exp"){ buff="exp"; *s=s->substr(3); } //Expo
		else if(s->substr(0,3) == "cos"){ buff="cos"; *s=s->substr(3); } //Cosinus
		else if(s->substr(0,3) == "sin"){ buff="sin"; *s=s->substr(3); } //Sinus
		else if(s->substr(0,3) == "tan"){ buff="tan"; *s=s->substr(3); } //Tan
		else if(s->substr(0,3) == "log"){ buff="log"; *s=s->substr(3); } //log
		else if(s->substr(0,2) == "ln"){ buff="ln"; *s=s->substr(2); } //Tan
		else{ buff.push_back(s->at(0)); *s=s->substr(1); }
	}
	return buff;
}

bool is_operator(string s){
	if(s == "+") return true;
	if(s == "-") return true;
	if(s == "/") return true;
	if(s == "*") return true;
	if(s == "^") return true;
	if(s == "%") return true;
	if(s == "exp") return true;
	if(s == "cos") return true;
	if(s == "sin") return true;
	if(s == "tan") return true;
	if(s == "log") return true;
	if(s == "ln") return true;
	return false;
}

bool is_operand(string s){
	if(is_operator(s) == false and s!="(" and s!=")") return true;
	return false;
}

bool bad_input(string s){ //renvoie true si le calcul n'est pas conforme
	bool f_operator=false;
	for(unsigned int i=0; i< s.size();i++){
		if(isdigit(s.at(i))){ f_operator=false; }
		else if(s.at(i) == '(' || s.at(i) == ')'){ f_operator=false; }
		else if(s.at(i) == '+' && !f_operator){ f_operator=true; }
		else if(s.at(i) == '-' && !f_operator){ f_operator=true; }
		else if(s.at(i) == '/' && !f_operator){ f_operator=true; }
		else if(s.at(i) == '*' && !f_operator){ f_operator=true; }
		else if(s.at(i) == '^' && !f_operator){ f_operator=true; }
		else if(s.at(i) == '%' && !f_operator){ f_operator=true; }
		else if(s.substr(i,3) == "exp"){ i+=3; f_operator=true; }
		else if(s.substr(i,3) == "cos"){ i+=3; f_operator=true; }
		else if(s.substr(i,3) == "sin"){ i+=3; f_operator=true; }
		else if(s.substr(i,3) == "tan"){ i+=3; f_operator=true; }
		else if(s.substr(i,3) == "log"){ i+=3; f_operator=true; }
		else if(s.substr(i,2) == "ln"){ i+=2; f_operator=true; }
		else{ return true; }
	}
	return false;
}

void calc_to_postfix(string s){
	list<string> l;
	stack<string> p;
	string buff;
	map<string,int> priority_op;

	priority_op["^"]=5;
	priority_op["exp"]=5;
	priority_op["cos"]=5;
	priority_op["sin"]=5;
	priority_op["tan"]=5;
	priority_op["*"]=3;
	priority_op["/"]=3;
	priority_op["+"]=2;
	priority_op["-"]=2;
	priority_op["("]=1;

	cout << "Start OK" << endl;

	while(!s.empty()){
		cout << "Boucle" << endl;
		cout << "s : " << s << endl;
		buff=separe(&s);
		cout << "Buff : " << buff << endl;
		if(is_operand(buff)){
			cout << "Operand : " <<buff<<endl;
			l.push_back(buff);
		}
		else if(buff == "("){
			cout << "push de (" << endl;
			p.push(buff);
		}
		else if(buff == ")"){
			cout << "Detection )" <<endl;

			while(!p.empty() && p.top()!="("){ 
				l.push_back(p.top());
				p.pop();
			}
			p.pop();
		}
		
		else{
			cout << "Operator : " << buff << endl;
			//if(p.empty() || p.top()=="(") p.push(buff);
			//else{
				while(!p.empty() /*&& p.top()!="("*/ && priority_op[buff] <= priority_op[p.top()]){
					l.push_back(p.top());
					p.pop();
				}
			//}
			p.push(buff);
		}
	}
	cout << "Pré Fin" << endl;
	while(!p.empty()){
		l.push_back(p.top());
		p.pop();
	}

//Affichage
	while(!l.empty()){
		cout << l.front();
		l.pop_front();
	}
	cout << endl;

}


int main(){
	string calc="1+3*2^2";
	string buff;
	//cout << "Calcul : ";
	//cin >> calc;

	//Calculator c(calc);
	//cout << c.getCalcul() << endl;


	if(bad_input(calc)){
		cout << "Syntaxe Error" << endl;
	}
/*
	while(!calc.empty()){
		buff=separe(&calc);
		cout << buff <<endl;
	}
*/
	//separe(&calc);


	calc_to_postfix(calc);
}