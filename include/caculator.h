#ifndef CACULATOR_H_
#define CACULATOR_h_ 1

#include <string>
#include <vector>
#include <stack>
#include <map>

#include "common.h"

class MyCaculator{
private:
    std::map<char, int> _opPriority;
    std::stack<double> _numStack;
    std::stack<char> _opStack;

    uint32_t _left_parentheses {0};
    uint32_t _right_parentheses {0};

public:
    MyCaculator() {
        _opPriority['+'] = 10;
        _opPriority['-'] = 10;
        _opPriority['*'] = 20;
        _opPriority['/'] = 20;
    }

    double execute();
    double caculator(const std::string &&input);
};


#endif