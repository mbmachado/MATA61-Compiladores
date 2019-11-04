#include <iostream>
#include "symbol/symbol.h"
#include "lexical/lexical.h"
#include "syntactic/syntactic.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Syntactic* syntactic = new Syntactic();
	syntactic->analyze("lexical/source-program-1.txt");
	/*
	ifstream file;
	Lexical* lexical = new Lexical();
	file.open("lexical/source-program-1.txt");

	while(!file.fail()) {
		Token t = lexical->getNextToken(file);
		
		t.serialize();
	}

	file.close();
	*/
	return 0;
}