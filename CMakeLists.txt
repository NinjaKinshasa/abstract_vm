cmake_minimum_required(VERSION 3.17)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 20)

add_executable(abstract_vm main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Parser.cpp Parser.h
        IOperand.cpp IOperand.h
        Operand.cpp Operand.h
        Instruction.cpp Instruction.h Value.cpp Value.h Executor.cpp Executor.h

        OperandFactory.cpp OperandFactory.h
        )