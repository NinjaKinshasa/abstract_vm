
#include "Lexer.h"
#include <iostream>
#include <string>


char popFirst(std::string &input)
{
    char first = input.at(0);

    if (first != '\0')
        input.erase(input.begin());

    return first;
}

TokenType identifyToken(std::string str)
{

    if (str == ";")
        return COMMENT;

    if (str == "\0")
        return END_OF_STRING;

    if (str == "\n")
        return NEWLINE;

    if (str == " ")
        return SPACE;

    if (str == "(")
        return PAR_OPEN;

    if (str == ")")
        return PAR_CLOSE;

    if (str == "-")
        return MINUS;

    if (str == "push")
        return W_push;

    if (str == "pop")
        return W_pop;

    if (str == "dump")
        return W_dump;

    if (str == "assert")
        return W_assert;

    if (str == "add")
        return W_add;

    if (str == "sub")
        return W_sub;

    if (str == "mul")
        return W_mul;

    if (str == "div")
        return W_div;

    if (str == "mod")
        return W_mod;

    if (str == "print")
        return W_print;

    if (str == "exit")
        return W_exit;

    if (str == "int8")
        return W_int8;

    if (str == "int16")
        return W_int16;

    if (str == "int32")
        return W_int32;

    if (str == "float")
        return W_float;

    if (str == "double")
        return W_double;

    if (str == "-")
        return MINUS;

    if (str == ".")
        return DOT;

    if (isdigit(str.at(0)))
        return DIGIT;

    return UNDEFINED;
}

bool isLanguageSymbol(char c)
{
    switch (c) {
        case '\0':
        case '\n':
        case ' ':
        case '(':
        case ')':
        case '-':
        case '.':
        case ';':
            return true;
        default:
            return false;
    }
}

Token getNextToken(std::string &input)
{
    static int lineCount = 1;

    std::string curTok = "";

    TokenType type = UNDEFINED;

    if (input.empty())
        return END_OF_STRING;

    while (!input.empty())
    {
        char c = popFirst(input);

        if (!curTok.empty() && isLanguageSymbol(c))
        {
            input = c + input;
            break;
        }

        curTok += c;

        type = identifyToken(curTok);

        if (type == COMMENT)
        {
            std::size_t found = input.find('\n') + 1;
            input.erase(0, found);
            lineCount++;
        }

        if (type != UNDEFINED)
            break;
    }

    if (type == UNDEFINED)
    {
        std::cout << "UNDEFINED TOKEN : '" << curTok << "' at line " << lineCount << std::endl;
    }

    if (type == DIGIT)
        return Token(type, curTok.at(0));

 //   std::cout << Token::valueOf(type) << std::endl;


    if (type == NEWLINE)
        lineCount++;

    return Token(type);
}

void preprocessing(std::vector<Token> &tokens)
{
    auto tok = std::begin(tokens);

    while (tok != std::end(tokens))
    {
        if (tok->getType() == SPACE)
        {
            tok = tokens.erase(tok);
        }
        else if (tok->getType() == COMMENT)
        {
            do
            {
                tok = tokens.erase(tok);
            }
            while (tok->getType() != NEWLINE);
        }
        else
            tok++;
    }

}

std::vector<Token> Lexer::lex(std::ifstream &input)
{
    auto tokens = std::vector<Token>();

    std::string input_str((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));


    Token token;

    do {

        token = getNextToken(input_str);
        tokens.push_back(token);

    } while (token.getType() != END_OF_STRING);

    //remove comments and spaces
    preprocessing(tokens);

  /*  for (auto &tok : tokens)
    {
        std::cout << Token::valueOf(tok.getType()) << std::endl;
    }
    */
    return tokens;
}
