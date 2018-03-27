#ifndef PILE_HPP
#define PILE_HPP

#include <string>
#include <stack>

using namespace std;

class Pile{
	private:
		stack<string> p;
		void calc_push(string s);
		string separe(string s);
	public:
		Pile(string s);
		void display();
		void calc_pop();
};

#endif