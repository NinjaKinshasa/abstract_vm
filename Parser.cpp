//
// Created by Matthieu on 26/07/2021.
//

#include <vector>
#include <iostream>
#include "Parser.h"
#include "Instruction.h"
#include "Operand.h"
#include "OperandFactory.h"


enum grammarType {
    S,
    INSTR,
    SEP,
    VALUE,
    N,
    Z
};

Token pop_front(std::vector<Token> &tokens)
{
    Token front = tokens.front();
 //   std::cout << Token::valueOf(front.getType()) << std::endl;
    tokens.erase(tokens.begin());
    return front;
}

void expect_symbol(int symbol, std::vector<Token> &tokens)
{
    Token tok = pop_front(tokens);

    if (tok.getType() != symbol)
    {
        std::cout << "WRONG SYMBOL : got " << Token::valueOf(tok.getType()) << " --> " << tok.getType() <<" instead of " << Token::valueOf(
                static_cast<TokenType>(symbol)) << std::endl;
        throw "Erreur expect mauvais symbol";

    }
}

void expect_SEP(std::vector<Token> &tokens)
{
    expect_symbol(NEWLINE, tokens);

    while (tokens.front().getType() == NEWLINE)
    {
        pop_front(tokens);
    }
}

std::string expect_N(std::vector<Token> &tokens)
{
    std::string n_str = "";

    Token tok = pop_front(tokens);

    if (tok.getType() == MINUS)
        n_str += "-";
    else if (tok.getType() == DIGIT)
    {
        n_str += tok.getValue();
    } else
        throw "error expecting digit";

    while (tokens.front().getType() == DIGIT)
    {
        tok = pop_front(tokens);
        n_str += tok.getValue();
    }

    return n_str;
}


std::string expect_Z(std::vector<Token> &tokens)
{
    std::string z_str = expect_N(tokens);

    expect_symbol(DOT, tokens);

    z_str += ".";

    Token tok = pop_front(tokens);


    if (tok.getType() == DIGIT)
    {
        z_str += tok.getValue();
    } else
        throw "error expecting digit";

    while(tokens.front().getType() == DIGIT)
    {
        tok = pop_front(tokens);
        z_str += tok.getValue();
    }

    return z_str;
}


/*
int expect_N(std::vector<Token> &tokens)
{
    int res = 0;
    bool positive = 1;

    Token tok = pop_front(tokens);

    if (tok.getType() == MINUS)
        positive = 0;
    else if (tok.getType() == DIGIT)
    {
        res = tok.getValue();
    } else
        throw "error expecting digit";

    while (tokens.front().getType() == DIGIT)
    {
        tok = pop_front(tokens);
        res = res * 10 + tok.getValue();
    }

    return (positive) ? res : -res;
}


double expect_Z(std::vector<Token> &tokens)
{
    int integer_part = expect_N(tokens);
    double decimal_part = 0;
    bool positive = integer_part >= 0;

    expect_symbol(DOT, tokens);

    Token tok = pop_front(tokens);

    double floating_level = 0.1;

    if (tok.getType() == DIGIT)
    {
        decimal_part = tok.getValue() * floating_level;
        floating_level /= 10;
    } else
        throw "error expecting digit";

    while(tokens.front().getType() == DIGIT)
    {
        tok = pop_front(tokens);
        decimal_part += tok.getValue() * floating_level;
        floating_level /= 10;
    }

    return positive ? integer_part + decimal_part : integer_part - decimal_part;
}
*/
const IOperand* expect_VALUE(std::vector<Token> &tokens)
{
    Token tok = pop_front(tokens);

    switch (tok.getType())
    {
        case W_int8:
        case W_int16:
        case W_int32:
        case W_float:
        case W_double:
            break;
        default:
            std::cout << "WRONG TYPE : " << Token::valueOf(tok.getType()) << std::endl;
            throw "Error wrong type";
    }

    expect_symbol(PAR_OPEN, tokens);

    std::map<TokenType, eOperandType> mapTokToOperand = {
            {W_int8, O_INT8},
            {W_int16, O_INT16},
            {W_int32, O_INT32},
            {W_float, O_FLOAT},
            {W_double, O_DOUBLE},
    };

    std::map<TokenType, std::string (*)(std::vector<Token> &)> mapTokToFunc = {
            {W_int8, &expect_N},
            {W_int16, &expect_N},
            {W_int32, &expect_N},
            {W_float, &expect_Z},
            {W_double, &expect_Z},
    };

    auto operand = OperandFactory().createOperand(mapTokToOperand[tok.getType()], mapTokToFunc[tok.getType()](tokens));

    expect_symbol(PAR_CLOSE, tokens);
    return operand;

}

Instruction expect_INSTR(std::vector<Token> &tokens)
{

    Token tok = pop_front(tokens);

    switch (tok.getType())
    {
        case W_push:
            return Instruction(I_PUSH, expect_VALUE(tokens));
        case W_pop:
            return Instruction(I_POP);
        case W_dump:
            return Instruction(I_DUMP);
        case W_assert:
            return Instruction(I_ASSERT, expect_VALUE(tokens));
        case W_add:
            return Instruction(I_ADD);
        case W_sub:
            return Instruction(I_SUB);
        case W_mul:
            return Instruction(I_MUL);
        case W_div:
            return Instruction(I_DIV);
        case W_mod:
            return Instruction(I_MOD);
        case W_print:
            return Instruction(I_PRINT);
        case W_exit:
            return Instruction(I_EXIT);
        default:
            std::cout << "error wrong token : " << Token::valueOf(tok.getType()) << std::endl;
            throw "ERROR wrong token";
    }
}

std::vector<Instruction> expect_S(std::vector<Token> &tokens)
{
    expect_SEP(tokens);
    std::vector<Instruction> instructions = std::vector<Instruction>();

    instructions.push_back(expect_INSTR(tokens));

    while(!tokens.empty() && tokens.front().getType() != END_OF_STRING)
    {
        expect_SEP(tokens);
        instructions.push_back(expect_INSTR(tokens));
    }

    return instructions;

}

void Parser::parse(std::vector<Token> &tokens)
{
    try {
        std::vector<Instruction> instructions = expect_S(tokens);
        int aaa = 1;

    } catch (char const *e) {
        std::cout << e << std::endl;
    }

    int test = 1;
}
