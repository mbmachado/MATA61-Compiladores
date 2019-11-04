#include <stack>
#include <string>
#include <exception>
#include <vector>
#include <map>

using namespace std;

/**
 * The Syntactic Analyzer class
 */
class Syntactic {
	private:
		stack<string> stack;
		map< pair<string, string>, vector<string> > M = {
		{{"programa", "programainicio"}, {"programainicio", "declaracoes", "execucaoinicio", "comando", "comandos", "fimexecucao", "fimprograma"}},
		{{"declaracoes", "execucaoinicio"}, {"&"}},
		{{"declaracoes", "definainstrucao"}, {"declaracao", "declaracoes"}},
		{{"declaracao", "definainstrucao"}, {"definainstrucao", "id", "como", "comando"}},
		{{"comandos", "id"}, {"comando", "comandos"}},
		{{"comandos", "fimexecucao"}, {"&"}},
		{{"comandos", "inicio"}, {"comando", "comandos"}},
		{{"comandos", "fim"}, {"&"}},
		{{"comandos", "repita"}, {"comando", "comandos"}},
		{{"comandos", "enquanto"}, {"comando", "comandos"}},
		{{"comandos", "se"}, {"comando", "comandos"}},
		{{"comandos", "mova"}, {"comando", "comandos"}},
		{{"comandos", "vire"}, {"comando", "comandos"}},
		{{"comandos", "pare"}, {"comando", "comandos"}},
		{{"comandos", "finalize"}, {"comando", "comandos"}},
		{{"comandos", "apague"}, {"comando", "comandos"}},
		{{"comandos", "acenda"}, {"comando", "comandos"}},
		{{"comandos", "aguarde"}, {"comando", "comandos"}},
		{{"comando", "id"}, {"instrucao"}},
		{{"comando", "inicio"}, {"bloco"}},
		{{"comando", "repita"}, {"iteracao"}},
		{{"comando", "enquanto"}, {"laco"}},
		{{"comando", "se"}, {"condicional"}},
		{{"comando", "mova"}, {"instrucao"}},
		{{"comando", "vire"}, {"instrucao"}},
		{{"comando", "pare"}, {"instrucao"}},
		{{"comando", "finalize"}, {"instrucao"}},
		{{"comando", "apague"}, {"instrucao"}},
		{{"comando", "acenda"}, {"instrucao"}},
		{{"comando", "aguarde"}, {"instrucao"}},
		{{"bloco", "inicio"}, {"inicio", "comandos", "fim"}},
		{{"iteracao", "repita"}, {"repita", "num", "vezes", "comando", "fimrepita"}},
		{{"laco", "enquanto"}, {"enquanto", "condicao", "faca", "comando", "fimpara"}},
		{{"condicional", "se"}, {"se", "condicao", "entao", "comando", "fimse", "condicionalExt"}},
		{{"condicionalExt", "id"}, {"&"}},
		{{"condicionalExt", "$"}, {"&"}},
		{{"condicionalExt", "fimexecucao"}, {"&"}},
		{{"condicionalExt", "inicio"}, {"&"}},
		{{"condicionalExt", "fim"}, {"&"}},
		{{"condicionalExt", "repita"}, {"&"}},
		{{"condicionalExt", "fimrepita"}, {"&"}},
		{{"condicionalExt", "enquanto"}, {"&"}},
		{{"condicionalExt", "fimpara"}, {"&"}},
		{{"condicionalExt", "se"}, {"&"}},
		{{"condicionalExt", "fimse"}, {"&"}},
		{{"condicionalExt", "senao"}, {"senao", "comando", "fimsenao"}},
		{{"condicionalExt", "fimsenao"}, {"&"}},
		{{"condicionalExt", "mova"}, {"&"}},
		{{"condicionalExt", "vire"}, {""}},
		{{"condicionalExt", "pare"}, {""}},
		{{"condicionalExt", "finalize"}, {""}},
		{{"condicionalExt", "apague"}, {""}},
		{{"condicionalExt", "acenda"}, {""}},
		{{"condicionalExt", "aguarde"}, {""}},
		{{"instrucao", "id"}, {"id"}},
		{{"instrucao", "mova"}, {"mova", "num", "instrucaoExt"}},
		{{"instrucao", "vire"}, {"vire", "para", "sentido"}},
		{{"instrucao", "pare"}, {"pare"}},
		{{"instrucao", "finalize"}, {"finalize"}},
		{{"instrucao", "apague"}, {"apague", "lampada"}},
		{{"instrucao", "acenda"}, {"acenda", "lampada"}},
		{{"instrucao", "aguarde"}, {"aguarde", "ate", "condicao"}},
		{{"instrucaoExt", "id"}, {"&"}},
		{{"instrucaoExt", "$"}, {"&"}},
		{{"instrucaoExt", "fimexecucao"}, {"&"}},
		{{"instrucaoExt", "inicio"}, {"&"}},
		{{"instrucaoExt", "fim"}, {"&"}},
		{{"instrucaoExt", "repita"}, {"&"}},
		{{"instrucaoExt", "fimrepita"}, {"&"}},
		{{"instrucaoExt", "enquanto"}, {"&"}},
		{{"instrucaoExt", "fimpara"}, {"&"}},
		{{"instrucaoExt", "se"}, {"&"}},
		{{"instrucaoExt", "fimse"}, {"&"}},
		{{"instrucaoExt", "fimsenao"}, {"&"}},
		{{"instrucaoExt", "mova"}, {"&"}},
		{{"instrucaoExt", "passo"}, {"passo"}},
		{{"instrucaoExt", "passos"}, {"passos"}},
		{{"instrucaoExt", "vire"}, {"&"}},
		{{"instrucaoExt", "pare"}, {"&"}},
		{{"instrucaoExt", "finalize"}, {"&"}},
		{{"instrucaoExt", "apague"}, {"&"}},
		{{"instrucaoExt", "acenda"}, {"&"}},
		{{"instrucaoExt", "aguarde"}, {"&"}},
		{{"condicao", "lampada"}, {"lampada", "estadoLampada"}},
		{{"condicao", "robo"}, {"robo", "estadoRobo"}},
		{{"condicao", "frente"}, {"frente", "robo", "bloqueada"}},
		{{"condicao", "direita"}, {"direita", "robo", "bloqueada"}},
		{{"condicao", "esquerda"}, {"esquerda", "robo", "bloqueada"}},
		{{"estadoLampada", "acesa"}, {"acesa", "a", "sentidoLampada"}},
		{{"estadoLampada", "apagada"}, {"apagada", "a", "sentidoLampada"}},
		{{"sentidoLampada", "frente"}, {"frente"}},
		{{"sentidoLampada", "direita"}, {"sentido"}},
		{{"sentidoLampada", "direita"}, {"sentido"}},
		{{"estadoRobo", "pronto"}, {"pronto"}},
		{{"estadoRobo", "ocupado"}, {"ocupado"}},
		{{"estadoRobo", "parado"}, {"parado"}},
		{{"estadoRobo", "movimentando"}, {"movimentando"}},
		{{"sentido", "direita"}, {"direita"}},
		{{"sentido", "esquerda"}, {"esquerda"}},	
	};

	public:
		Syntactic();
		void analyze();
		bool isTerminal(string top);
		bool isTableErrorInput(string top, string input);
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
		Robot_L_Syntactic_Exception(int line) {
			message = "Error Exception: estrutura incorreta na linha " + to_string(line) + ".";
		}

		Robot_L_Syntactic_Exception(int line, string terminal) {
			message = "Error Exception: um '" + terminal + "' era esperado na linha " + to_string(line) + ".";
		}

		virtual const char* what() const throw() {
			return message.c_str();
		}  
};