//
// Created by Matthieu on 27/07/2021.
//

#ifndef ABSTRACT_VM_VALUE_H
#define ABSTRACT_VM_VALUE_H

enum valueType {
    V_UNDEFINED,
    V_INT8,
    V_INT16,
    V_INT32,
    V_FLOAT,
    V_DOUBLE
};

class Value {
    valueType type;
    union {
        int _integer;
        double _double;
    };

public:
    Value() : type(V_UNDEFINED), _integer(0) {}
    Value(valueType type, int val) : type(type), _integer(val) {}
    Value(valueType type, double val) : type(type), _double(val) {}
};


#endif //ABSTRACT_VM_VALUE_H
