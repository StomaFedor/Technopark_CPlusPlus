#pragma once
#include "ICalculatable.h"
#include <iostream>
#include <cmath>

class Arcsin : public ICalculatable
{
public:
	Arcsin(ICalculatable& number) : _number(number.Calculate()) { }

	double Calculate() override
	{
		if (_number > 1 || _number < -1)
			throw std::invalid_argument("The number in the arcsin does not pass the limit");
		return asin(_number);
	}
private:
	double _number;
};