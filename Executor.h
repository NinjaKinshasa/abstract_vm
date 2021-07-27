#ifndef ABSTRACT_VM_EXECUTOR_H
#define ABSTRACT_VM_EXECUTOR_H


#include <vector>
#include <stack>
#include "Instruction.h"
#include "IOperand.h"

class Executor {
    std::stack<IOperand> stack;

public:
    Executor();
    void run(std::vector<Instruction> instructions);
    void push(Value value);
};


#endif //ABSTRACT_VM_EXECUTOR_H
