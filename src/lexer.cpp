#include <lexer.hpp>

namespace lexer 
{
	std::vector<std::string> keywords = {
		"mov",
		"jmp",
		"section",
		"double",
		"quad",
		"byte",
		"word",
		"macro"
	};
	std::vector<std::string> regs64 = {
		"rax",
		"rbx",
		"rcx",
		"rdx",
		"rsi",
		"rdi",
		"rbp",
		"rsp",
		"r8",
		"r9",
		"r10",
		"r11",
		"r12",
		"r13",
		"r14",
		"r15"
	};
	std::vector<std::string> regs32 = {
		"eax",
		"ebx",
		"ecx",
		"edx",
		"esi",
		"edi",
		"ebp",
		"esp"
	};
	std::vector<std::string> regs16 = {
		"ax",
		"bx",
		"cx",
		"dx",
		"si",
		"di",
		"bp",
		"sp"
	};

	bool isstrlit(char c) {
		return std::isprint(c) && c != '\0';
	}
	std::vector<token> lex(std::string& buffer)
	{
		std::vector<token> tokens_ret;
		std::string::iterator buffer_itr = buffer.begin();
		while (buffer_itr < buffer.end())
		{
			/* Early bail */
			if(*buffer_itr == ' ' || *buffer_itr == '\t' || *buffer_itr == '\n')
			{
				buffer_itr++;
				continue;
			}
			token new_token;
			switch (*buffer_itr)
			{
			case ',':
				new_token = {",", COMMA};
				buffer_itr++;
				break;
			case '{':
				new_token = {"{", OPEN_CURLY_BRACKET};
				buffer_itr++;
				break;
			case '}':
				new_token = {"}", CLOSE_CURLY_BRACKET};
				buffer_itr++;
				break;
			case '(':
				new_token = {"(", OPEN_PARENTHESIS};
				buffer_itr++;
				break;
			case ')':
				new_token = {")", CLOSE_PARENTHESIS};
				buffer_itr++;
				break;
			case '*':
				new_token = {"*", ASTERISK};
				buffer_itr++;
				break;
			case '=':
				new_token = {"=", EQUAL};
				buffer_itr++;
				break;
			case '$':
				new_token = {"$", DOLLAR};
				buffer_itr++;
				break;
			case '-':
				new_token = {"-", MINUS};
				buffer_itr++;
				break;
			case '+':
				new_token = {"+", PLUS};
				buffer_itr++;
				break;
			default:
				if(std::isdigit(*buffer_itr))
				{
					while(std::isdigit(*buffer_itr)) 
						new_token.data += *buffer_itr++;
					new_token.type = NUMBER;
				}
				else if(std::isalpha(*buffer_itr) || *buffer_itr == '_')
				{
					while(std::isalnum(*buffer_itr) || *buffer_itr == '_') 
						new_token.data += *buffer_itr++;

					/* Checks if its a Register */
					if(std::find(regs64.begin(), regs64.end(), new_token.data) != regs64.end())
						new_token.type = REGISTER64;
					else if(std::find(regs32.begin(), regs32.end(), new_token.data) != regs32.end())
						new_token.type = REGISTER32;
					else if(std::find(regs16.begin(), regs16.end(), new_token.data) != regs16.end())
						new_token.type = REGISTER16;
					/* Checks if its a keyword */
					else if(std::find(keywords.begin(), keywords.end(), new_token.data) != keywords.end())
						new_token.type = KEYWORD;
					/* All are false, assign as a label */
					else
						new_token.type = LABEL;
				}
				else if(isstrlit(*buffer_itr))
				{
					while(isstrlit(*buffer_itr)) 
						new_token.data += *buffer_itr++;
					new_token.type = STRING;
				}
				else
				{
					std::cerr << "Unknown Token: " << *buffer_itr << "\n";
					exit(-1);
				}
				break;
			}		
			tokens_ret.push_back(new_token);
		}
		return tokens_ret;
	}
}