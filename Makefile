all:
	g++ main.cpp lexical/lexical.cpp symbol/symbol.cpp syntactic/syntactic.cpp semantic/semantic.cpp code-generator/code.cpp -std=c++11
