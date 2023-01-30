#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <lexer/lexer.h>

using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Not enough arguments.\n"
			   "Usage: %s <Filename> <Out name>\n", argv[0]);
		return 1;
	}

	ifstream handler;
	string line;
	string file;

	handler.open(argv[1]);
	if (handler.is_open()) {
		while (getline(handler, line))
			file += line + '\n';
		handler.close();
	} else {
		printf("Error: Unable to open file %s!\n", argv[1]);
	}

	Lexer::init(file);
	
	list<Lexer::Token> tokens = Lexer::lex();
	printf("%d\n", tokens.size());

	for (auto token : tokens) {
		printf("%s\n", token.content.data());
	}

	return 0;
}
