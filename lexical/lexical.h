#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <exception>
#ifndef LEXICAL
#define LEXICAL

using namespace std;

/**
 * Vector that keeps the source code
 */
vector<string> lexicalErrors({
	"Identificador mal formado"
});

struct Robot_L_Lexical_Exception : public exception {
   const char * what () const throw () {
      //TODO passar um parametro code para pegar a mensagem no vector lexicalErrors e ver como obter a linha e coluna
      return "Lexical Exception: ...";
   }
};

/**
 * Vector that keeps the source code
 */
vector<string> sourceCode;

/**
 * Vector that keeps the reserved words
 */
vector<string> reservedWords({ 
	"programainicio",
	"execucaoinicio",
	"fimexecucao",
	"fimprograma",
	"definainstrucao",
	"como",
	"inicio",
	"fim",
	"repita",
	"vezes",
	"fimrepita",
	"enquanto",
	"faca",
	"fimpara",
	"se",
	"entao",
	"fimse",
	"senao",
	"fimsenao",
	"mova",
	"passos"
	"vire para",
	"pare",
	"finalize",
	"apague lampada",
	"acenda lampada",
	"acenda lampada",
	"robo pronto",
	"robo ocupado",
	"robo parado",
	"robo movimentando",
	"frente robo bloqueada",
	"direita robo bloqueada",
	"esquerda robo bloqueada",
	"lampada acessa a frente",
	"lampada apagada a frente",
	"lampada acessa a esquerda",
	"lampada apagada a esquerda",
	"lampada acessa a direita",
	"lampada apagada a direita",
	"esquerda",
	"direita"
});

/**
 * Reads the source program
 *
 */
void readSourceProgram();

#endif