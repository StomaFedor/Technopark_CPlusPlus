#pragma once
#include "ICalculatable.h"

class Substraction : public ICalculatable
{
public:
	Substraction(ICalculatable& firstNum, ICalculatable& secondNum) : _firstNum(firstNum.Calculate()), _secondNum(secondNum.Calculate()) { }

	double Calculate() override
	{
		return _firstNum - _secondNum;
	}
private:
	double _firstNum;
	double _secondNum;
};