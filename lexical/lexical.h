#include <vector>
#include <string.h>
#include <exception>

using namespace std;

/**
 * The Token class
 */
class Token {      
	private:            
    	string name;       
    	int attribute;

    public:
    	Token(string n, int a) {
    		name = n;
    		attribute = a; 
    	}

    	string getName() {
    		return name;
    	}

    	int getAttribute() {
    		return attribute;
    	}
};

/**
 * The Robot_L_Lexical_Exception class
 * @extends exception
 *
 */
class Robot_L_Lexical_Exception : public exception {
	private:
		int code;

	public:
		Robot_L_Lexical_Exception(int c) {
			code = c;
		}

		virtual const char* what() const throw() {
			switch (code) {
				case 1:
					return "Error Exception: Identificador mal formado na linha y, coluna x.";
				break;
				default:
					return "Error Exception: código de erro desconhecido.";
			}
		}  
};

