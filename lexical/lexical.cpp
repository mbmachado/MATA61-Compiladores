#include "lexical.h"

void readSourceProgram() {
	string line;
	ifstream file;
	file.open("source-program-1.txt");

	while(getline(file, line)) {
       sourceCode.push_back(line);
    }

    file.close();
}
