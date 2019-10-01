#include "lexical.h"
#include "../symbol/symbol.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Lexical::Lexical() {}

Token Lexical::getNextToken(istream& file) {
	try {
		int state = 0;
		char c; string lexeme = "";
		SymbolTable* st = SymbolTable::getInstance();
		
		while (file.get(c)) {
			lexeme += c;
			
			switch (state) {
				case 0:
					//cout << "no estado 0, comparando: '" << c << "'" << endl;
					if(c == '#') state = 5;
					else if(isDelimiter(c)) state = 7;
					else if(isLetter(c)) state = 1;
					else if(isDigit(c)) state = 3;
					else throw Robot_L_Lexical_Exception(4);
					break;
				case 1:
					//cout << "no estado 1, comparando: '" << c << "'" << endl;
					if(isDelimiter(c)) { state = 2; file.unget(); lexeme.pop_back(); }
					else if(isAlphanumeric(c)) state = 1;
					else throw Robot_L_Lexical_Exception(1);
					//cout << "next state: " << state << endl;
					break;
				case 2:
					//cout << "estado 2" << endl;
					file.unget();
					lexeme.pop_back();
					return Token(st->getTokenName(lexeme), st->installID(lexeme, 0, 0));
				case 3:
					//cout << "estado 3" << endl;
					if(isDelimiter(c)) { state = 4; file.unget(); lexeme.pop_back(); }
					else if(isDigit(c)) state = 3;
					else throw Robot_L_Lexical_Exception(2);
					break;
				case 4:
					//cout << "estado 4" << endl;
					file.unget();
					lexeme.pop_back();
					return Token("num",  st->installNum(lexeme, 0, 0));
				case 5:
					//cout << "estado 5" << endl;
					if(!isNewLine(c)) state = 5; 
					else { state = 6; file.unget(); }
					break;
				case 6:
					//cout << "estado 6" << endl;
					state = 0;
					lexeme = "";
					break;
				case 7:
					//cout << "estado 7" << endl;
					if(isDelimiter(c)) state = 7;
					else { state = 8; file.unget(); }
					break;
				case 8:
					//cout << "estado 8" << endl;
					state = 0;
					file.unget();
					lexeme = "";
					break;
			}
		}

		return Token("EOF", 0);
	} catch (Robot_L_Lexical_Exception e) {
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

bool Lexical::isDigit(char c) {
	if(c == '0' || c == '1' || 
		c == '2' || c == '3' || 
		c == '4' || c == '5' ||
		c == '6' || c == '7' || 
		c == '8' || c == '9' 
	) return true;
	return false;
}

bool Lexical::isLetter(char c) {
	if(c == 'a' || c == 'A' || 
		c == 'b' || c == 'B' || 
		c == 'c' || c == 'C' ||
		c == 'd' || c == 'D' || 
		c == 'e' || c == 'E' || 
		c == 'f' || c == 'F' ||
		c == 'g' || c == 'G' ||
		c == 'h' || c == 'H' ||
		c == 'i' || c == 'I' ||
		c == 'j' || c == 'J' ||
		c == 'k' || c == 'K' ||
		c == 'l' || c == 'L' ||
		c == 'm' || c == 'M' ||
		c == 'n' || c == 'N' ||
		c == 'o' || c == 'O' ||
		c == 'p' || c == 'P' ||
		c == 'q' || c == 'Q' ||
		c == 'r' || c == 'R' ||
		c == 's' || c == 'S' ||
		c == 't' || c == 'T' ||
		c == 'u' || c == 'U' ||
		c == 'v' || c == 'V' ||
		c == 'x' || c == 'X' ||
		c == 'y' || c == 'Y' ||
		c == 'w' || c == 'W' ||
		c == 'z' || c == 'Z'
	) return true;
	return false;
}

bool Lexical::isAlphanumeric(char c) {
	if(isDigit(c) || isLetter(c)) 
		return true;
	return false;
}

bool Lexical::isNewLine(char c) {
	if(c == '\n' || c == '\r') 
		return true;
	return false;
}

bool Lexical::isDelimiter(char c) {
	// ASCII way c == 9 || c == 32 || c == 10 || c == 13
	if(isNewLine(c) || c == '	' || c == ' ')
		return true;
	return false;
}

Token::Token(string n, int a) {
	name = n;
    attribute = a;
}

string Token::getName() {
	return name;
}
    
int Token::getAttribute() {
	return attribute;
}		