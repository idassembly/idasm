#pragma once

#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace lexer
{
	enum token_type {
		LABEL,
		OPEN_PARENTHESIS,
		CLOSE_PARENTHESIS,
		OPEN_CURLY_BRACKET,
		CLOSE_CURLY_BRACKET,
		KEYWORD,
		NUMBER,
		STRING,
		COMMA,
		ASTERISK,
		EQUAL,
		DOLLAR,
		MINUS,
		PLUS,
		REGISTER64,
		REGISTER32, 
		REGISTER16
	};
	typedef struct {
		std::string data;
		token_type type;
	} token;

	std::vector<token> lex(std::string buffer);
} // namespace lexer
