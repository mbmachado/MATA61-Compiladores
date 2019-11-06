all:
	g++ main.cpp lexical/lexical.cpp symbol/symbol.cpp syntactic/syntactic.cpp semantic/semantic.cpp -std=c++11
