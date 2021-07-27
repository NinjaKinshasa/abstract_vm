#ifndef ABSTRACT_VM_LEXER_H
#define ABSTRACT_VM_LEXER_H


#include <vector>
#include <fstream>

#include "Token.h"

class Lexer {
public:
    static std::vector<Token> lex(std::ifstream &input);
};


#endif //ABSTRACT_VM_LEXER_H
