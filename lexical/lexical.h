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
		int currentLine;
		int currentColumn;

	public:
		Lexical();
		Token getNextToken(istream& file);
		bool isDigit(char c);
		bool isLetter(char c);
		bool isAlphanumeric(char c);
		bool isNewLine(char c);
		bool isDelimiter(char c);
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
				case 2:
					return "Error Exception: Número mal formado na linha y, coluna x.";
				case 3:
					return "Error Exception: Valor numérico muito grande na linha y, coluna x.";
				case 4:
					return "Error Exception: Símbolo não reconhecido na linha y, coluna x.";
				default:
					return "Error Exception: código de erro desconhecido.";
			}
		}  
};

