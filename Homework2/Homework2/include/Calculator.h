#pragma once
#include "ICalculatable.h"
#include "Addition.h"
#include "Arccos.h"
#include "Arcsin.h"
#include "Multiplication.h"
#include "Number.h"
#include "Subtraction.h"

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

const std::string OPERATORS = "+-*asinacos";

class Calculator : public ICalculatable
{
public: 
	Calculator(std::string expression) : _expression(expression) { }

	void SetExpression(std::string expression);

	double Calculate() override;

private:
	std::vector<std::string> Split(const std::string& str, const char separator);

	int Priority(std::string& str);

	bool isOperand(std::string& str);

	std::vector<std::string> infixToPostfix(std::vector<std::string>& infix);

	double GetResult(std::vector<std::string>& postfix);

	std::string _expression;
};