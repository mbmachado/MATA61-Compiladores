#include "syntactic.h"
#include "../lexical/lexical.h"
#include "../symbol/symbol.h"
#include <iostream>
#include <fstream>

using namespace std;

Syntactic::Syntactic() {
	stack.push("programa");
}


void Syntactic::analyze() {
	ifstream file;
	Lexical* lexical = new Lexical();
	SymbolTable* st = SymbolTable::getInstance();
	file.open("lexical/source-program-1.txt");

	cout << " em analyze" << endl;
	while(!file.fail()) {		
		cout << " primeiro while" << endl;
		Token token = lexical->getNextToken(file);
		Symbol s = st->getSymbol(token.getAttribute());
		string top = stack.top();
		token.serialize();

		while(!stack.empty()) {
			cout << " segundo while" << endl;
			try {
				if(top.compare(token.getName()) == 0) {
					cout << " primeiro if" << endl;

					stack.pop();
					token = lexical->getNextToken(file);
					s = st->getSymbol(token.getAttribute());
				} else if(isTerminal(top)) {
					cout << " segundo if" << endl;

					throw Robot_L_Syntactic_Exception(1, s.getLine());
				} else if(isTableErrorInput(top, token.getName())) {
					cout << " terceiro if" << endl;

					throw Robot_L_Syntactic_Exception(1, s.getLine());
				} else if(!isTableErrorInput(top, token.getName())) {
					cout << " quarto if" << endl;

					stack.pop();
					vector<string> production = M[{top, token.getName()}];
					cout << "Escolheu: " << top << " ::= ";
					for(vector<string>::iterator it = production.begin(); it != production.end(); ++it) { 
						cout << *it << ' ';
					}
					cout << endl;

					for(vector<string>::reverse_iterator rit = production.rbegin(); rit != production.rend(); ++rit) { 
						stack.push(*rit);
					} 
				}

				top = stack.top();
			} catch (Robot_L_Syntactic_Exception e) {
				cout << e.what() << endl;
				exit(EXIT_FAILURE);
			}
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

bool Syntactic::isTableErrorInput(string top, string name) {
	map< pair<string, string>, vector<string> >::iterator it;
	it = M.find({top, name});

	if (it == M.end())
		return true;
	return false;
}