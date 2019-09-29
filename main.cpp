#include "symbol/symbol.h"
#include "lexical/lexical.h"
#include "syntactic/syntactic.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	try {
		// TODO ficar chamando getToken do analisador sintático?

		// Usar quando encontrar um erro léxico
		throw Robot_L_Lexical_Exception(); 
	} catch (Robot_L_Lexical_Exception e) {
		cout << e.what() << endl;
	}

	return 0;
}