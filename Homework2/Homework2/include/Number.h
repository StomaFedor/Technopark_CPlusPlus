#pragma once
#include "ICalculatable.h"

class Number : public ICalculatable
{
public:
	Number(double number) : _number(number) { }

	double Calculate() override
	{
		return _number;
	}
private:
	double _number;
};