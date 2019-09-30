#include "lexical.h"

using namespace std;

Lexical* Lexical::instance = 0;

Lexical::Lexical() {}

Lexical* Lexical::getInstance() {
    if (instance == 0)
    {
        instance = new Lexical();
    }

    return instance;
}

Token getNextToken() {
	Token t("id", 1);
	return t;
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