#include <vector>
#include <string>
#include <set>

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
		static SymbolTable* instance;
		SymbolTable();
		set<string> keyWords{"programainicio", "execucaoinicio", "fimexecucao", "fimprograma", "definainstrucao", 
			"como", "inicio", "fim", "repita", "vezes", "fimrepita", "enquanto", "faca", "fimpara", "se", "entao", 
			"fimse", "senao", "fimsenao", "mova", "passo", "passos", "vire", "para", "pare", "finalize", "apague", 
			"acenda", "lampada", "aguarde", "ate", "robo", "pronto", "ocupado", "parado", "movimentando", "frente",
			"direita", "esquerda", "bloqueada", "acessa", "apagada", "a"
		};
		vector<Symbol> symbols;
	
	public:
		SymbolTable(const SymbolTable&) = delete;
		SymbolTable& operator=(const SymbolTable&) = delete;
		static SymbolTable* getInstance();
		string getTokenName(string lexeme);
		int installID(string lexeme, int column, int line);
		int installNum(string lexeme, int column, int line);
		bool isKeyWord();
};
