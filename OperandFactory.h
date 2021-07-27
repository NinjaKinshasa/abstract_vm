#ifndef ABSTRACT_VM_OPERANDFACTORY_H
#define ABSTRACT_VM_OPERANDFACTORY_H


#include <map>
#include "IOperand.h"

//template pas très intelligent il vaudrait mieux mettre des methodes statiques...

class OperandFactory {
public:

    OperandFactory();

    IOperand const * createOperand(eOperandType type, std::string const & value ) const;

private:
    typedef const IOperand *(OperandFactory::*Create_func)(const std::string &) const;
    std::map<eOperandType, Create_func> map;

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};


#endif //ABSTRACT_VM_OPERANDFACTORY_H
