#include <sstream>
#include <iostream>
#include <fstream>
#include "symbol/symbol.h"
#include "lexical/lexical.h"
#include "syntactic/syntactic.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	try {
		string line;
		ifstream file;
		file.open("lexical/source-program-1.txt");
		file.exceptions(ifstream::failbit | ifstream::badbit);

		while(getline(file, line)) {
		   cout << line << endl;
		}

    	file.close();
		
		throw Robot_L_Lexical_Exception(1); 
	} catch (Robot_L_Lexical_Exception e) {
		cout << e.what() << endl;
	} catch (ifstream::failure e) {
		cout << "Um erro ocorreu ao manipular o arquivo.";
	}

	return 0;
}