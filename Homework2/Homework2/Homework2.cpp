// Homework2.cpp: определяет точку входа для приложения.
//

#include <iostream>

#include "Calculator.h"

int main(int argc, char* argv[])
{
	try
	{
        if (argc != 2)
            throw std::invalid_argument("Incorrect command line data");

        double res = Calculator(argv[1]).Calculate();

        std::cout << res;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}