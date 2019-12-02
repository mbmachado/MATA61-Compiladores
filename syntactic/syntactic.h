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
		stack<string> _stack;
		map< pair<string, string>, vector<string> > M = {
		{{"programa", "programainicio"}, {"programainicio", "r0", "declaracoes", "execucaoinicio", "comando", "comandos", "fimexecucao", "fimprograma", "r1"}},
		{{"declaracoes", "execucaoinicio"}, {"&"}},
		{{"declaracoes", "definainstrucao"}, {"declaracao", "declaracoes"}},
		{{"declaracao", "definainstrucao"}, {"definainstrucao", "r2", "id", "como", "comando", "r3"}},
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
		{{"bloco", "inicio"}, {"inicio", "r4", "comandos", "fim"}},
		{{"iteracao", "repita"}, {"repita", "r5", "num", "vezes", "comando", "fimrepita", "r6"}},
		{{"laco", "enquanto"}, {"enquanto", "r7", "condicao", "faca", "comando", "fimpara", "r8"}},
		{{"condicional", "se"}, {"se", "r9", "condicao", "entao", "comando", "fimse", "r10", "condicionalExt"}},
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
		{{"condicionalExt", "vire"}, {"&"}},
		{{"condicionalExt", "pare"}, {"&"}},
		{{"condicionalExt", "finalize"}, {"&"}},
		{{"condicionalExt", "apague"}, {"&"}},
		{{"condicionalExt", "acenda"}, {"&"}},
		{{"condicionalExt", "aguarde"}, {"&"}},
		{{"instrucao", "id"}, {"id", "r20"}},
		{{"instrucao", "mova"}, {"mova", "numOpcional"}},
		{{"instrucao", "vire"}, {"vire", "para", "sentido"}},
		{{"instrucao", "pare"}, {"pare", "r21"}},
		{{"instrucao", "finalize"}, {"finalize", "r22"}},
		{{"instrucao", "apague"}, {"apague", "lampada", "r23"}},
		{{"instrucao", "acenda"}, {"acenda", "lampada", "r24"}},
		{{"instrucao", "aguarde"}, {"aguarde", "ate", "condicao"}},
		{{"numOpcional", "id"}, {"&"}},
		{{"numOpcional", "num"}, {"num", "instrucaoExt"}},
		{{"numOpcional", "$"}, {"&"}},
		{{"numOpcional", "fimexecucao"}, {"&"}},
		{{"numOpcional", "inicio"}, {"&"}},
		{{"numOpcional", "fim"}, {"&"}},
		{{"numOpcional", "repita"}, {"&"}},
		{{"numOpcional", "fimrepita"}, {"&"}},
		{{"numOpcional", "enquanto"}, {"&"}},
		{{"numOpcional", "fimpara"}, {"&"}},
		{{"numOpcional", "se"}, {"&"}},
		{{"numOpcional", "fimse"}, {"&"}},
		{{"numOpcional", "fimsenao"}, {"&"}},
		{{"numOpcional", "mova"}, {"&"}},
		{{"numOpcional", "vire"}, {"&"}},
		{{"numOpcional", "pare"}, {"&"}},
		{{"numOpcional", "finalize"}, {"&"}},
		{{"numOpcional", "apague"}, {"&"}},
		{{"numOpcional", "acenda"}, {"&"}},
		{{"numOpcional", "aguarde"}, {"&"}},
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
		{{"condicao", "frente"}, {"frente", "robo", "bloqueada", "r11"}},
		{{"condicao", "direita"}, {"direita", "robo", "bloqueada", "r12"}},
		{{"condicao", "esquerda"}, {"esquerda", "robo", "bloqueada", "r13"}},
		{{"estadoLampada", "acesa"}, {"acesa", "a", "r14", "sentidoLampada"}},
		{{"estadoLampada", "apagada"}, {"apagada", "a", "r15", "sentidoLampada"}},
		{{"sentidoLampada", "frente"}, {"frente", "r16"}},
		{{"sentidoLampada", "direita"}, {"sentido"}},
		{{"sentidoLampada", "direita"}, {"sentido"}},
		{{"estadoRobo", "pronto"}, {"pronto", "r25"}},
		{{"estadoRobo", "ocupado"}, {"ocupado", "r19"}},
		{{"estadoRobo", "parado"}, {"parado"}},
		{{"estadoRobo", "movimentando"}, {"movimentando"}},
		{{"sentido", "direita"}, {"direita", "r17"}},
		{{"sentido", "esquerda"}, {"esquerda", "r18"}},	
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
			message = "Error Exception: Estrutura incorreta na linha " + to_string(line) + ".";
		}

		Robot_L_Syntactic_Exception(int line, string terminal) {
			message = "Error Exception: Um '" + terminal + "' era esperado na linha " + to_string(line) + ".";
		}

		virtual const char* what() const throw() {
			return message.c_str();
		}  
};