#include "lexical.h"

using namespace std;

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