#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#include "../include/caculator.h"
#include "../include/common.h"

// #define DEBUG

using std::map;
using std::string;
using std::vector;
using std::stack;


bool isOperator(const char ch) {
    return (ch == '+' || \
            ch == '-' || \
            ch == '*' || \
            ch == '/'? true: false);
}

double MyCaculator::execute() {
    double result = 0;
    double rightOperand = _numStack.top();   _numStack.pop();
    double leftOperand = _numStack.top();  _numStack.pop();
    int op = _opStack.top();    _opStack.pop();

    switch (op) {
        case '+':
            result = leftOperand + rightOperand;
            break;
        case '-':
            result = leftOperand - rightOperand;
            break;
        case '*':
            result = leftOperand * rightOperand;
            break;
        case '/':
            result = leftOperand / rightOperand;
            break;
        default:
            LOGE << "invalid operator.\n";
    }

    #ifdef DEBUG
    LOGI << "--------------\n";
    printf("op: %c\n", op);
    LOGI << "leftOperand: " << leftOperand << "\n";
    LOGI << "rightOperand: " << rightOperand << "\n";
    LOGI << "result: " << result << "\n";
    #endif

    _numStack.push(result);
    return result;
}

double MyCaculator::caculator(const string &&input) {

    double result = 0;
    double number = 0;
    string numberStr;

    for (int i = 0; i < input.size(); ++i) {
        if (isspace(input[i])) {
            continue;
        }

        //  handle consequent operator
        if (i + 1 < input.size()) {
            if (isOperator(input[i]) && isOperator(input[i+1])) {
                LOGE << "invalid expression.\n";
                return 0;
            }
        }

        //  handle '(' and ')'
        if (input[i] == '(') {
            _left_parentheses++;
            continue;
        }
        if (input[i] == ')') {
            number = strtof(numberStr.c_str(), nullptr);
            _numStack.push(number);
            numberStr.clear();
            execute();
            _right_parentheses++;
            continue;
        }

        //  handle digit
        if (isdigit(input[i])) {
            numberStr.push_back(input[i]);
            continue;
        }

        if (isOperator(input[i])) {
            if (!numberStr.empty()) {
                _numStack.push(strtof(numberStr.c_str(), nullptr));
            }
            
            numberStr.clear();

            while (!_opStack.empty() && _numStack.size() > 1 && \
                    _opPriority[input[i]] < _opPriority[_opStack.top()] && \
                    _left_parentheses == _right_parentheses) {
                execute();
            }
            
            _opStack.push(input[i]);
        }
    }

    //  handle the last number
    if (!numberStr.empty()) {
        number = strtof(numberStr.c_str(), nullptr);
        _numStack.push(number);
    }

    while (_numStack.size() != 1) {
        execute();
    }

    //  if _left_parentheses isn't euqal to 0, the expression is invalid 
    if (_left_parentheses != _right_parentheses) {
        LOGE << "invalid expression.\n";
        return 0;
    }

    result = _numStack.top();   _numStack.pop();
    return result;
}