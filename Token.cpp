//
// Created by Matthieu on 26/07/2021.
//

#include "Token.h"

std::string Token::valueOf(TokenType type) {
    return tokToVal[type];
}

Token::Token() :type(UNDEFINED){}
Token::Token(TokenType type) : type(type) {}
Token::Token(TokenType type, char val) : type(type), value(val) {}

TokenType Token::getType() {
    return type;
}

uint8_t Token::getValue() {
    return value;
}

