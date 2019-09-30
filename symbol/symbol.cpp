#include "symbol.h"

using namespace std;

Symbol::Symbol(string le, int c, int li) {
	lexeme = le;
	column = c;
	line = li;
}

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

SymbolTable::SymbolTable() {}

int SymbolTable::insertSymbol(Symbol s) {
	symbols.push_back(s);
	//TODO retornar posição inserida;
	return 1;
}

bool SymbolTable::isKeyWord() {
	//TODO verificar se lexema é keyword;
	return true;
}