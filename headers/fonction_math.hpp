#ifndef FONCTION_MATH_HPP
#define FONCTION_MATH_HPP

#include "Erreur.hpp"
#include <string>
#include <cmath>
#include <map>

const string op_size_1("+ % - / * ^");
const string op_size_1_spec("n");
const string op_size_2("");
const string op_size_3("exp cos sin tan log");
const string op_size_4("sqrt fact");
const string op_size_5("arccos arcsin arctan");

const string PI("3.14159265");


struct Priority{
		map<string,int> op;
		void fill_priority();
};


double factoriel(long double n); // Calculer le factoriel d'un nombre, (le factroriel d'un nombre négatif n'existe pas)
bool is_operator(string s); //Test si le paramètre est un operateur
bool is_operand(string s); //Test si l'operand est un nombre
int modulo(int n, int n1); // fontion modulo
/*********************************************************************************
	Prend en entrée 3 string, a=chiffre 1, b=chiffre 2 et op=opération à faire
	Renvoie le resultat sous forme de string
**********************************************************************************/
string exec_calc(string a, string b, string op);

#endif