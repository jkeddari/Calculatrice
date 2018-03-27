#include "pile.hpp"

#include <iostream>

Pile::Pile(string s){
	this->calc_push(s);
}

void Pile::calc_push(string s){
	for(unsigned int i=0; i<s.size();i++){
		this->p.push(s.substr(i,1));
	}
}

void Pile::calc_pop(){
	while(this->p.empty()==false){
		cout << p.top() << endl;
		p.pop();
		
	}
}

void Pile::display(){

}
