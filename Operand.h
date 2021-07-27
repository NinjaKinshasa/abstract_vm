//
// Created by Matthieu on 27/07/2021.
//

#ifndef ABSTRACT_VM_OPERAND_H
#define ABSTRACT_VM_OPERAND_H

#include "IOperand.h"

template<typename T>
class Operand : public IOperand {

private:
    T value;
    std::string test;
public:
    Operand(const std::string &input) {
        test = input;
    }

    int getPrecision( void ) const {
        return 10;
    }

    eOperandType getType( void ) const {
        return O_UNDEFINED;
    }

    IOperand const * operator+( IOperand const & rhs ) const {
        return nullptr;
    }


    IOperand const * operator-( IOperand const & rhs ) const {
        return nullptr;
    }


    IOperand const * operator*( IOperand const & rhs ) const {
        return nullptr;
    }


    IOperand const * operator/( IOperand const & rhs ) const {
        return nullptr;
    }


    IOperand const * operator%( IOperand const & rhs ) const {
        return nullptr;
    }

    std::string const & toString( void ) const {
        return "jsppp";
    }
};




#endif //ABSTRACT_VM_OPERAND_H
