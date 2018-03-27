#include "calculator.hpp"

Calculator::Calculator(string calcul){
	this->calcul=calcul;
}

string Calculator::getCalcul(){
	return this->calcul;
}

bool Calculator::check_calcul(){
	return true;
}

string Calculator::Result(){
	return "test";
}

