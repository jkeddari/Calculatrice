#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <list>
#include <stack>
#include <map>
#include "Erreur.hpp"
#include <cmath>
#include <iostream>

using namespace std;

const map<string,int> priority_op;

const string op_size_1("+ - / * ^ % !");
const string op_size_2("ln");
const string op_size_3("exp cos sin tan log");
const string op_size_4("sqrt");
const string op_size_5("arccos arcsin arctan");


class Calculator{
	private:
		string calcul;
		string result;
		list<string> *calc_postfix;
		bool calcul_ok=false;
		map<string,int> priority_op;

		
	/***********************************************************************************/
	/*		M E T H O D E 		I N I T I A L I S A T I O N 	*/
		void bad_input(); //Check le calcul
		void fill_priority(); //Fonction d'init des priorité
	/***********************************************************************************/

	/***********************************************************************************/
	/*		M E T H O D E 		S T A T I C 	*/
		static list<string> split_calc(string s); //Découpe le calcul en list
		static bool is_operator(string s); //Test si le paramètre est un operateur
		static bool is_operand(string s); //Test si l'operand est un nombre
		/*****************************************************
			Prend en entrée 3 string, a=chiffre 1, b=chiffre 2 et op=opération à faire
			Renvoie le resultat sous forme de string
		******************************************************/
		static string exec_calc(string a, string b, string op);
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