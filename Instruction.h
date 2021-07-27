#ifndef ABSTRACT_VM_INSTRUCTION_H
#define ABSTRACT_VM_INSTRUCTION_H

#include "Value.h"
#include "IOperand.h"

enum InstructionType
{
    I_PUSH,
    I_POP,
    I_DUMP,
    I_ASSERT,
    I_ADD,
    I_SUB,
    I_MUL,
    I_DIV,
    I_MOD,
    I_PRINT,
    I_EXIT,
};

class Instruction {
    InstructionType type;
    const IOperand *operand;

public:
    Instruction(InstructionType type, const IOperand *operand);

    Instruction(InstructionType type);

    InstructionType getType();

    const IOperand *getOperand();
};


#endif //ABSTRACT_VM_INSTRUCTION_H
