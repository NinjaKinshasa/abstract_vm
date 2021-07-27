#ifndef ABSTRACT_VM_TOKEN_H
#define ABSTRACT_VM_TOKEN_H

#include <string>
#include <map>

enum TokenType {
    W_push,
    W_pop,
    W_dump,
    W_assert,
    W_add,
    W_sub,
    W_mul,
    W_div,
    W_mod,
    W_print,
    W_exit,

    W_int8,
    W_int16,
    W_int32,
    W_float,
    W_double,

    SPACE,
    COMMENT,
    NEWLINE,
    ASSIGN,
    PAR_OPEN,
    PAR_CLOSE,
    MINUS,
    DOT,
    DIGIT,
    END_OF_STRING,
    UNDEFINED,
};


static std::map<TokenType, const std::string> tokToVal = {
        {TokenType::W_push,     "push"},
        {TokenType::W_pop,      "pop"},
        {TokenType::W_dump,     "dump"},
        {TokenType::W_assert,   "assert"},
        {TokenType::W_add,      "add"},
        {TokenType::W_sub,      "sub"},
        {TokenType::W_mul,      "mul"},
        {TokenType::W_div,      "div"},
        {TokenType::W_mod,      "mod"},
        {TokenType::W_print,    "print"},
        {TokenType::W_exit,     "exit"},

        {TokenType::W_int8,     "int8"},
        {TokenType::W_int16,    "int16"},
        {TokenType::W_int32,    "int32"},
        {TokenType::W_float,    "float"},
        {TokenType::W_double,   "double"},

        {TokenType::COMMENT,    ";"},
        {TokenType::NEWLINE,    "newline"},
        {TokenType::ASSIGN,     ":="},
        {TokenType::PAR_OPEN,   "("},
        {TokenType::PAR_CLOSE,  ")"},
        {TokenType::MINUS,      "-"},
        {TokenType::DOT,        "."},
        {TokenType::DIGIT,      "DIGIT"},
        {TokenType::SPACE,      "SPACE"},
        {TokenType::END_OF_STRING,"END OF STRING"},
};


class Token {


private:
    TokenType type;

    uint8_t value;

public:
    Token();
    Token(TokenType type);
    Token(TokenType type, char val);

    static std::string valueOf(TokenType type);
    TokenType getType();
    uint8_t getValue();
};


#endif //ABSTRACT_VM_TOKEN_H
