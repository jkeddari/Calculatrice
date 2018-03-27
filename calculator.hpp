#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "pile.hpp"
using namespace std;

class Calculator{
	private:
		string calcul;
		bool check_calcul();
	public:
		Calculator(string calcul);
		string getCalcul();
		string Result();
};

#endif