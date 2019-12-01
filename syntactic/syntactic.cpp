#include "syntactic.h"
#include "../lexical/lexical.h"
#include "../symbol/symbol.h"
#include "../semantic/semantic.h"
#include "../code-generator/code.h"
#include <regex>
#include <iostream>
#include <fstream>

using namespace std;

Syntactic::Syntactic() {
	_stack.push("$");
	_stack.push("programa");
}

void Syntactic::analyze() {
	ifstream file;
	regex _regex("r[0-9]+"); 
	Lexical* lexical = new Lexical();
	Semantic* semantic = new Semantic();
	Code* codeGenerator = new Code();
	SymbolTable* st = SymbolTable::getInstance();
	file.open("lexical/source-program-1.txt");

	Token token = lexical->getNextToken(file);
	Symbol s = st->getSymbol(token.getAttribute());
	string top = _stack.top();

	while(top.compare("$") != 0) {
		//cout << "TOPO_PILHA: " << top << " | ENTRADA: " << token.getName() << endl;
		try {
			if(regex_match(top, _regex)) {
				//cout << "  Topo da pilha com Gera Código, desempilha" << endl;
				_stack.pop();
				codeGenerator->generateCode(top);
			} else if(top.compare(token.getName()) == 0) {
				//cout << "  Topo da pilha e Entrada iguais, desempilha" << endl;
				_stack.pop();
				semantic->analyze(token.getName(), s.getLexeme(), s.getLine());
				token = lexical->getNextToken(file);
				s = st->getSymbol(token.getAttribute());
			} else if(isTerminal(top)) {
				//cout << "  Topo da pilha com terminal diferente da Entrada" << endl;
				throw Robot_L_Syntactic_Exception(s.getLine(), top);
			} else if(isTableErrorInput(top, token.getName())) {
				//cout << "  M[Topo, Entrada] retorna erro" << endl;
				throw Robot_L_Syntactic_Exception(s.getLine());
			} else if(!isTableErrorInput(top, token.getName())) {
				//cout << "  M[Topo, Entrada] retorna uma regra e esta foi empilhada" << endl;
				_stack.pop();

				vector<string> production = M[{top, token.getName()}];
				for(vector<string>::reverse_iterator rit = production.rbegin(); rit != production.rend(); ++rit) { 
					string symbol = *rit;
					if(symbol.compare("&") != 0)
						_stack.push(symbol);
				}
			}

			top = _stack.top();
		} catch (Robot_L_Syntactic_Exception e) {
			cout << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	file.close();
}

bool Syntactic::isTerminal(string top) {
	SymbolTable* st = SymbolTable::getInstance();
	if(st->isKeyWord(top) || top.compare("id") == 0 || top.compare("num") == 0)
		return true;
	return false;
}

bool Syntactic::isTableErrorInput(string top, string input) {
	map< pair<string, string>, vector<string> >::iterator it;
	it = M.find({top, input});

	if (it == M.end())
		return true;
	return false;
}