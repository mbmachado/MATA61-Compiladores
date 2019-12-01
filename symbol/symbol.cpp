#include "symbol.h"
#include "../lexical/lexical.h"
#include <algorithm>
#include <ctype.h>

using namespace std;

Symbol::Symbol(string le, int c, int li) {
	lexeme = le;
	column = c;
	line = li;
}

Symbol::Symbol(string le) {
	lexeme = le;
	column = 0;
	line = 0;
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
        instance = new SymbolTable();

    return instance;
}

SymbolTable::SymbolTable() {}

string SymbolTable::getToken(string lexeme) {
	transform(lexeme.begin(), lexeme.end(), lexeme.begin(), ::tolower);
	
	if(isKeyWord(lexeme))
		return lexeme;
	return "id";	
}

int SymbolTable::installID(string lexeme, int column, int line) {
	symbols.push_back(Symbol(lexeme, column, line));
	return symbols.size() - 1;
}

int SymbolTable::installNum(string lexeme, int column, int line) {
	if(lexeme.size() > 7)
		throw Robot_L_Lexical_Exception(3, line, column);

	symbols.push_back(Symbol(lexeme));
	return symbols.size() - 1;
}

bool SymbolTable::isKeyWord(string lexeme) {
	set<string>::iterator it;
	it = keyWords.find(lexeme);
	
	if(it != keyWords.end())
		return true;
	return false;
}

Symbol SymbolTable::getSymbol(int index) {
	Symbol s = symbols[index];
	return s;
}

void SymbolTable::insert(string id) {
	transform(id.begin(), id.end(), id.begin(), ::tolower);
	identifiers.insert(id);
}

bool SymbolTable::find(string id) {
	transform(id.begin(), id.end(), id.begin(), ::tolower);

	set<string>::iterator it;
	it = identifiers.find(id);

	if(it != identifiers.end())
		return true;
	return false;
}