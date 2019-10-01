#include "symbol.h"
#include "../lexical/lexical.h"
#include <algorithm>
#include <ctype.h>

using namespace std;

// Atributos de identificador
Symbol::Symbol(string le, int c, int li) {
	lexeme = le;
	column = c;
	line = li;
}

// Atributos de número
Symbol::Symbol(int v) {
	value = v;
}

string Symbol::getLexeme() {
	return lexeme;
}

int Symbol::getColumn() {
	return column;
}

int Symbol::getLine() {
	return line;
}

SymbolTable* SymbolTable::instance = 0;

SymbolTable* SymbolTable::getInstance() {
    if (instance == 0)
    {
        instance = new SymbolTable();
    }

    return instance;
}

SymbolTable::SymbolTable() {}

string SymbolTable::getTokenName(string lexeme) {
	transform(lexeme.begin(), lexeme.end(), lexeme.begin(), ::tolower);
	
	set<string>::iterator it;
	it = keyWords.find(lexeme);

	if(it != keyWords.end()) {
		return lexeme;
	} else {
		return "id";
	}
}

int SymbolTable::installID(string lexeme, int column, int line) {
	symbols.push_back(Symbol(lexeme, column, line));
	return symbols.size() - 1;
}

int SymbolTable::installNum(string lexeme, int column, int line) {
	int value = 1;
	if(lexeme.size() > 6) {
		throw Robot_L_Lexical_Exception(3);
	} else {
		value = stoi(lexeme, nullptr);
	}

	symbols.push_back(Symbol(value));
	return symbols.size() - 1;
}

bool SymbolTable::isKeyWord() {
	//TODO verificar se lexema é keyword;
	return true;
}