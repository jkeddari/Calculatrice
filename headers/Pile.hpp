#ifndef PILE_HPP
#define PILE_HPP

#include <stack>
#include <string>
using namespace std;

class Pile{
	private:
		stack<string> s;
	public:
		Pile();
		void pop();
		void push(string value);
		string top();
		size_t size();
		bool empty();
};


#endif