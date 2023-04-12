#pragma once
#include "ICalculatable.h"

class Multiplication : public ICalculatable
{
public:
	Multiplication(ICalculatable& firstNum, ICalculatable& secondNum) : _firstNum(firstNum.Calculate()), _secondNum(secondNum.Calculate()) { }

	double Calculate() override
	{
		return _firstNum * _secondNum;
	}
private:
	double _firstNum;
	double _secondNum;
};