#include <vector>
#include <string.h>

using namespace std;

/**
 * The Symbol class
 */
class Symbol {
	private:
		string lexeme;
		int column;
		int line;
		int value;


	public:
		Symbol(string le, int c, int li) {
			lexeme = le;
			column = c;
			line = li;
		}

		Symbol(int v) {
			value = v;
		}

		string getLexeme() {
			return lexeme;
		}

		int getColumn() {
			return column;
		}

		int getLine() {
			return line;
		}		
	
};

/**
 * The SymbolTable class
 */
class SymbolTable {
	private:
		vector<string> keyWords{"programainicio", "execucaoinicio", "fimexecucao", "fimprograma", "definainstrucao", 
			"como", "inicio", "fim", "repita", "vezes", "fimrepita", "enquanto", "faca", "fimpara", "se", "entao", 
			"fimse", "senao", "fimsenao", "mova", "passo", "para", "pare", "finalize", "apague", "acenda", "lampada", 
			"acessa", "apagada", "robo", "pronto", "ocupado", "parado", "movimentando", "bloqueada", "a", "frente", 
			"direita", "esquerda" 
		};
		vector<Symbol> symbols;
	
	public:
		SymbolTable();
	
		int insertSymbol(Symbol s) {
			symbols.push_back(s);
			//TODO retornar posição inserida;
			return 1;
		}

		bool isKeyWord() {
			//TODO verificar se lexema é keyword;
			return true;
		}
};
