#include <iostream>
#include "symbol/symbol.h"
#include "lexical/lexical.h"
#include "syntactic/syntactic.h"
#include "semantic/semantic.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Syntactic* syntactic = new Syntactic();
	syntactic->analyze();
	return 0;
}