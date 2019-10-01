#include <string>
#include <exception>
#include <iostream>

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
		int line;
		int column;

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
		string message;

	public:
		Robot_L_Lexical_Exception(int code, int line, int column) {
			if (code == 1) message = "Error Exception: Identificador mal formado na linha " + to_string(line) + ", coluna " + to_string(column) +".";
			else if (code == 2) message = "Error Exception: Número mal formado na linha " + to_string(line) + ", coluna " + to_string(column) +".";
			else if (code == 3) message = "Error Exception: Valor numérico muito grande na linha " + to_string(line) + ", coluna " + to_string(column) +".";
			else if (code == 4) message = "Error Exception: Símbolo não reconhecido na linha " + to_string(line) + ", coluna " + to_string(column) +".";
			else message = "Error Exception: erro desconhecido.";
		}

		virtual const char* what() const throw() {
			return message.c_str();
		}  
};

