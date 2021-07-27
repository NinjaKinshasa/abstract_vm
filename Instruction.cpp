//
// Created by Matthieu on 27/07/2021.
//

#include "Instruction.h"

Instruction::Instruction(InstructionType type, const IOperand *operand) : type(type), operand(operand) {}

Instruction::Instruction(InstructionType type) : type(type) {}

InstructionType Instruction::getType() {
    return type;
}

const IOperand* Instruction::getOperand() {
    return operand;
}

