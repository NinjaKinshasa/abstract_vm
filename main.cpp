#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Operand.h"

int main() {
    std::ifstream exemple("../exemples/exemple1.avm");

    if (!exemple.good())
    {
        std::cout << "Le fichier n'existe pas" << std::endl;
        return 1;
    }

    auto tokens = Lexer::lex(exemple);
    Parser::parse(tokens);

    Operand<int> test = Operand<int>("test");

    return 0;
}
