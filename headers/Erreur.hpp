#ifndef ERREUR_HPP
#define ERREUR_HPP

#include <exception>
#include <string>

using namespace std;

class Erreur: public exception{
	public:
		Erreur(int number=0, string const& desc="", int level=0) throw(){
			m_number=number;
			m_desc=desc;
			m_level=level;
		}
		
		virtual const char* what() const throw(){
			return m_desc.c_str();
		}

		int getLevel() const throw(){
			return m_level;
		}
		virtual ~Erreur() throw(){}

	private:
		int m_level;
		int m_number;
		string m_desc;
};

#endif