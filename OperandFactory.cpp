//
// Created by Matthieu on 27/07/2021.
//

#include <vector>
#include "Operand.h"
#include "OperandFactory.h"

IOperand const *OperandFactory::createOperand(eOperandType type, const std::string &value) const
{
    // plus court qu'un switch mais pas vraiment plus lisible
    // le sujet demande
    Create_func fnc_ptr = this->map.at(type);
    return (this->*fnc_ptr)(value);
}

IOperand const *OperandFactory::createInt8(const std::string &value) const
{
    return new Operand<int8_t>(value);
}

IOperand const *OperandFactory::createInt16(const std::string &value) const
{
    return new Operand<int16_t>(value);
}

IOperand const *OperandFactory::createInt32(const std::string &value) const
{
    return new Operand<int32_t>(value);
}

IOperand const *OperandFactory::createFloat(const std::string &value) const
{
    return new Operand<float_t>(value);
}

IOperand const *OperandFactory::createDouble(const std::string &value) const
{
    return new Operand<double_t>(value);
}

OperandFactory::OperandFactory()
{
    map = {
            {O_INT8, &OperandFactory::createInt8},
            {O_INT16, &OperandFactory::createInt16},
            {O_INT32, &OperandFactory::createInt32},
            {O_FLOAT, &OperandFactory::createFloat},
            {O_DOUBLE, &OperandFactory::createDouble},
        };
}
