#include "lexical.h"
#include <iostream>

using namespace std;

Lexical::Lexical() {}

Token Lexical::getNextToken(istream& file) {
	try {
		int state = 0;
		char c; string lexeme = "";
		while (file.get(c)) {

			lexeme += c;

			//cout << "Lendo:" << "'" << c << "'" << endl;
			//cout << "Lexema atual:" << "'" << lexeme << "'" << endl;
			switch (state) {
				case 0:
					//cout << "estado 0" << endl;
					if(c == '#') state = 5;
					else if(isDigit(c)) state = 3;
					else if(isLetter(c)) state = 1;
					else if(isDelimiter(c)) state = 7;
					else throw Robot_L_Lexical_Exception(4);
					break;
				case 1:
					//cout << "estado 1" << endl;
					if(isAlphanumeric(c)) state = 1;
					else state = 2; 
					break;
				case 2:
					//cout << "estado 2" << endl;
					file.unget();
					lexeme.pop_back();
					return Token("id", lexeme);
				case 3:
					//cout << "estado 3" << endl;
					if(isDigit(c)) state = 3;
					else state = 4;
					break;
				case 4:
					//cout << "estado 4" << endl;
					file.unget();
					lexeme.pop_back();
					return Token("num", lexeme);
				case 5:
					//cout << "estado 5" << endl;
					if(c != '\n') state = 5; 
					else state = 6;
					break;
				case 6:
					lexeme = "";
					state = 0;
					//cout << "estado 6" << endl;
					break;
				case 7:
					//cout << "estado 7" << endl;
					if(c == 9 || c == 32 || c == 10) state = 7;
					else state = 8;
					break;
				case 8:
					//cout << "estado 8" << endl;
					lexeme = "";
					state = 0;
					file.unget();
					break;
			}
		}
	} catch (Robot_L_Lexical_Exception e) {
		cout << e.what() << endl;
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

bool Lexical::isDelimiter(char c) {
	//c == 9 || c == 32 || c == 10 ASCII way
	if( c == '	') {
		//cout << "tab" << endl;
		return true;
	} else if(c == '\n') {
		//cout << "newLine" << endl;
		return true;
	} else if(c == ' ') {
		//cout << "blank" << endl;
		return true;
	}
	return false;
}

Token::Token(string n, string a) {
	name = n;
    attribute = a;
}

string Token::getName() {
	return name;
}
    
string Token::getAttribute() {
	return attribute;
}		