#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/**
 * The token struct
 */
typedef struct token {
	string name;
	string attribute;
} Token;

/**
 * Symbol Table Vector
 */
vector<string> symbolTable;
