#include "Calculator.h"

void Calculator::SetExpression(std::string expression)
{
    _expression = expression;
}

double Calculator::Calculate()
{
    std::vector<std::string> infix = Split(_expression, ' ');
    std::vector<std::string> postfix = infixToPostfix(infix);
    double res = GetResult(postfix);
    return res;
}

std::vector<std::string> Calculator::Split(const std::string& str, const char separator)
{
    std::vector<std::string> result;
    std::string s;
    std::stringstream streamData(str);
    while (std::getline(streamData, s, separator))
        result.push_back(s);
    return result;
}

int Calculator::Priority(std::string& str)
{
    if (str == "(")
        return 4;
    else if (str == "*")
        return 2;
    else if (str == "+" || str == "-")
        return 3;
    else
        throw std::invalid_argument("The calculator does not support the transferred operation");

}

bool Calculator::isOperand(std::string& str)
{
    return OPERATORS.find(str) == std::string::npos;
}

std::vector<std::string> Calculator::infixToPostfix(std::vector<std::string>& infix)
{
    std::stack<std::string> stack;
    std::vector<std::string> postfix;
    for each (std::string str in infix) {
        if (str == "(" || str == "asin" || str == "acos")
            stack.push(str);
        else if (str == ")") {
            while (stack.top() != "(") {
                postfix.push_back((stack.top()));
                stack.pop();
            }
            stack.pop();
            if (!stack.empty() && (stack.top() == "asin" || stack.top() == "acos")) {
                postfix.push_back((stack.top()));
                stack.pop();
            }
        }
        else if (isOperand(str)) {
            postfix.push_back(str);
        }
        else {
            while (!stack.empty() && Priority(str) >= Priority(stack.top())) {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(str);
        }
    }
    while (!stack.empty()) {
        postfix.push_back(stack.top());
        stack.pop();
    }
    return postfix;
}


double Calculator::GetResult(std::vector<std::string>& postfix)
{
    std::stack<double> stack;
    for each (std::string str in postfix) {
        if (isOperand(str))
            stack.push(std::stof(str));
        else if (str == "+") {
            Number secondNum = Number(stack.top());
            stack.pop();
            Number firstNum = Number(stack.top());
            stack.pop();
            stack.push(Addition(firstNum, secondNum).Calculate());
        }
        else if (str == "-") {
            Number secondNum = Number(stack.top());
            stack.pop();
            Number firstNum = Number(stack.top());
            stack.pop();
            stack.push(Substraction(firstNum, secondNum).Calculate());
        }
        else if (str == "*") {
            Number secondNum = Number(stack.top());
            stack.pop();
            Number firstNum = Number(stack.top());
            stack.pop();
            stack.push(Multiplication(firstNum, secondNum).Calculate());
        }
        else if (str == "asin") {
            Number number = Number(stack.top());
            stack.pop();
            stack.push(Arcsin(number).Calculate());
        }
        else if (str == "acos") {
            Number number = Number(stack.top());
            stack.pop();
            stack.push(Arccos(number).Calculate());
        }
    }
    return stack.top();
}