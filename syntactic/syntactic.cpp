#include "syntactic.h"
#include "../lexical/lexical.h"
#include "../symbol/symbol.h"
#include <iostream>
#include <fstream>

using namespace std;

Syntactic::Syntactic() {
	stack.push("programa");
}


void Syntactic::analyze(string fileName) {
	ifstream file;
	Lexical* lexical = new Lexical();
	file.open(fileName);

	while(!file.fail()) {
		SymbolTable* st = SymbolTable::getInstance();
		Token token = lexical->getNextToken(file);
		Symbol s = st->getSymbol(token.getAttribute());
		string top = stack.top();
		while(!stack.empty()) {
			try {
				if(top.compare(token.getName())) {
					stack.pop();
					token = lexical->getNextToken(file);
					s = st->getSymbol(token.getAttribute());
				} else if(isTerminal(top)) {
					throw Robot_L_Syntactic_Exception(1, s.getLine(), s.getColumn());
				} else if(false/*TODO*/) {
					throw Robot_L_Syntactic_Exception(1, s.getLine(), s.getColumn());
				} else if(false/*TODO*/) {
					// TODO
					stack.pop();
				}

				top = stack.top();
			} catch (Robot_L_Lexical_Exception e) {
				cout << e.what() << endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	file.close();
}

bool Syntactic::isTerminal(string top) {
	// TODO
	return true;
}