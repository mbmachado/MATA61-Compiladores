#include <sstream>
#include <iostream>
#include <fstream>
#include "symbol/symbol.h"
#include "lexical/lexical.h"
#include "syntactic/syntactic.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream file;
	Lexical* lexical = new Lexical();
	file.open("lexical/source-program-1.txt");

	while(!file.fail()) {
		Token t = lexical->getNextToken(file);
		cout << "Token: <" << t.getName() << ", " << t.getAttribute() << ">" << endl;
	}

	file.close();
	return 0;
}