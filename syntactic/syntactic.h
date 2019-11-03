#include <string>
#include <exception>

using namespace std;

/**
 * The Syntactic Analyzer class
 */
class Syntactic {
	private:

	public:
		Syntactic();
};

/**
 * The Robot_L_Syntactic_Exception class
 * @extends exception
 *
 */
class Robot_L_Syntactic_Exception : public exception {
	private:
		string message;

	public:
		Robot_L_Syntactic_Exception(int code, int line, int column) {
			if (code == 1) message = "Error Exception: erro sintático desconhecido na linha " + to_string(line) + ", coluna " + to_string(column) +".";
			else message = "Error Exception: erro desconhecido.";
		}

		virtual const char* what() const throw() {
			return message.c_str();
		}  
};