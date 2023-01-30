#include <lexer.hpp>
const char* token_type_str[] = {
	"LABEL",
	"OPEN_PARENTHESIS",
	"CLOSE_PARENTHESIS",
	"OPEN_CURLY_BRACKET",
	"CLOSE_CURLY_BRACKET",
	"KEYWORD",
	"NUMBER",
	"STRING",
	"COMMA",
	"ASTERISK",
	"EQUAL",
	"DOLLAR",
	"MINUS",
	"PLUS",
	"REGISTER64",
	"REGISTER32",
	"REGISTER16"
};
int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		std::ifstream asm_input(argv[1]);
		std::stringstream asm_ss;
		asm_ss << asm_input.rdbuf();
		std::string asm_str = asm_ss.str();

		std::vector<lexer::token> asm_tokens = lexer::lex(asm_str);
		for(lexer::token& t : asm_tokens)
		{
			if(t.data == "\n")
				std::cout << token_type_str[t.type] << " : " << "\\n" << "\n";
			else
				std::cout << token_type_str[t.type] << " : " << t.data << "\n";
		}
	}
	else
	{
		std::cerr << "Invalid number of arguments: " << argc - 1 << "\n";
	}
	return 0;
}
