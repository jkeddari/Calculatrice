#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <list>
#include <stack>
#include <map>
#include "Erreur.hpp"
#include <cmath>
#include <iostream>

#include "fonction_math.hpp"

using namespace std;


class Calculator{
	private:
		string calcul;
		string result;
		list<string> *calc_postfix;
		

		
	/***********************************************************************************/
	/*		M E T H O D E 		I N I T I A L I S A T I O N 	*/
		bool bad_input(); //Check le calcul
	/***********************************************************************************/

	/***********************************************************************************/
	/*		M E T H O D E 		S T A T I C 	*/
		static list<string> split_calc(string s); //Découpe le calcul en list
	/***********************************************************************************/

	/***********************************************************************************/
	/*		E X E C U T I O N 		D U 		C A L C U L 	*/	
		void calc_to_postfix(); //Tranforme le calcul en calcul postfixé
		void postfix_eval(); //Execute le calcul
		void erase_zero(); //Supprime les zéros en trop après la virgule
	/***********************************************************************************/
		
	public:
		Calculator(string calcul);
		~Calculator();
		string getCalcul();
		string getResult();
};

#endif