#ifndef ABSTRACT_VM_PARSER_H
#define ABSTRACT_VM_PARSER_H


#include "Token.h"

class Parser {

public:
    static void parse(std::vector<Token> &tokens);

};


#endif //ABSTRACT_VM_PARSER_H
