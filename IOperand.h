#ifndef ABSTRACT_VM_IOPERAND_H
#define ABSTRACT_VM_IOPERAND_H

#include <string>

enum eOperandType {
    O_UNDEFINED,
    O_INT8,
    O_INT16,
    O_INT32,
    O_FLOAT,
    O_DOUBLE
};

enum eOperandPrecision {
    P_INT8,
    P_INT16,
    P_INT32,
    P_FLOAT,
    P_DOUBLE
};

class IOperand {
        public:
        virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
        virtual eOperandType getType( void ) const = 0; // Type of the instance
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        virtual std::string const & toString( void ) const = 0; // String representation of the instance
        virtual ~IOperand( void ) {}
};


#endif //ABSTRACT_VM_IOPERAND_H
