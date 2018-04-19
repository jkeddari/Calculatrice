#include "../headers/Pile.hpp"

Pile::Pile(){}

void Pile::pop(){
	s.pop();
}

void Pile::push(string value){
	s.push(value);
}
 
string Pile::top(){
	return s.top();
}

size_t Pile::size(){
	return s.size();
}

bool Pile::empty(){
	return s.empty();
}