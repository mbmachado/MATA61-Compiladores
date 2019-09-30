#include <string>
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
    	Token(string n, int a);
    	string getName();
    	int getAttribute();
};

/**
 * The Lexical Analyzer class
 */
class Lexical {
	private:
		static Lexical* instance;
		Lexical();

	public:
		static Lexical* getInstance();
		Token getNextToken();
	
};

/**
 * The Robot_L_Lexical_Exception class
 * @extends exception
 *
 */
class Robot_L_Lexical_Exception : public exception {
	private:
		int code;
		int line;
		int column;

	public:
		Robot_L_Lexical_Exception(int c) : code(c) {}
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

