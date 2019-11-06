#include <string>
#include <exception>

using namespace std;

/**
 * The Semantic Analyzer class
 */
class Semantic {
	private:
		int state;

	public:
		Semantic();
		void analyze(string symbol, int line);
};

/**
 * The Robot_L_Semantic_Exception class
 * @extends exception
 *
 */
class Robot_L_Semantic_Exception : public exception {
	private:
		string message;

	public:
		Robot_L_Semantic_Exception(int code, int line) {
			if (code == 1) message = "Error Exception: Identificador redeclarado na linha " + to_string(line) + ".";
			else if (code == 2) message = "Error Exception: Identificador indeclarado na linha " + to_string(line) + ".";
			else if (code == 3) message = "Error Exception: Um 'aguarde ate robo pronto' era esperado na linha " + to_string(line) + ".";
			else if (code == 4) message = "Error Exception: 'vire para ...' antecedido por 'vire para ...' com sentido oposto na linha " + to_string(line) + ".";
			else message = "Error Exception: erro desconhecido.";
		}

		virtual const char* what() const throw() {
			return message.c_str();
		}  
};

