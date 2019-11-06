#include "semantic.h"
#include <iostream>

Semantic::Semantic() {
	state = 0;
}

void Semantic::analyze(string symbol, int line) {
	try {
		
		switch (state) {
			case 0:
				if(symbol.compare("definainstrucao") == 0) state = 1;
				else if(symbol.compare("id") == 0) { 
					if(/*Não está na tabela de simbolos*/ false) throw Robot_L_Semantic_Exception(2, line);
				} else if(symbol.compare("mova") == 0) state = 2;
				else if(symbol.compare("vire") == 0) state = 9;
				break;
			case 1:
				if(symbol.compare("id") == 0) {
					if(/*Está na tabela de simbolos*/ false) throw Robot_L_Semantic_Exception(1, line);
					else {/*Inserir na tabela de simbolos*/state = 0;} 
				} break;
			case 2:
				if(symbol.compare("num") == 0) state = 3;
				break;
			case 3:
				if(symbol.compare("passo") == 0 || symbol.compare("passos") == 0) state = 8;
				else if(symbol.compare("aguarde") == 0) state = 4;
				else throw Robot_L_Semantic_Exception(3, line);
				break;
			case 4:
				if(symbol.compare("ate") == 0) state = 5;
				break;
			case 5:
				if(symbol.compare("robo") == 0) state = 6;
				else throw Robot_L_Semantic_Exception(3, line);
				break;
			case 6:
				if(symbol.compare("pronto") == 0) state = 7;
				else throw Robot_L_Semantic_Exception(3, line);
				break;
			case 7:
				state = 0;
				break;
			case 8:
				if(symbol.compare("aguarde") == 0) state = 4;
				else throw Robot_L_Semantic_Exception(3, line);
				break;
			case 9:
				if(symbol.compare("para") == 0) state = 10;
				break;
			case 10:
				if(symbol.compare("direita") == 0) state = 11;
				else if(symbol.compare("esquerda") == 0) state = 12;
				break;
			case 11:
				if(symbol.compare("vire") == 0) state = 13;
				else state = 0;
				break;
			case 12:
				if(symbol.compare("vire") == 0) state = 14;
				else state = 0;
				break;
			case 13:
				if(symbol.compare("para") == 0) state = 15;
				break;
			case 14:
				if(symbol.compare("para") == 0) state = 16;
				break;
			case 15:
				if(symbol.compare("esquerda") == 0) throw Robot_L_Semantic_Exception(4, line);
				else if(symbol.compare("direita") == 0) state = 11;
				break;
			case 16:
				if(symbol.compare("direita") == 0) throw Robot_L_Semantic_Exception(4, line);
				else if(symbol.compare("esquerda") == 0) state = 12;
				break;
		}

	} catch (Robot_L_Semantic_Exception e) {
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}