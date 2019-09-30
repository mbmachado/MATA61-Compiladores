#include <vector>
#include <string>

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
		Symbol(string le, int c, int li);
		Symbol(int v);
		string getLexeme();
		int getColumn();
		int getLine();	
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
		int insertSymbol(Symbol s);
		bool isKeyWord();
};
