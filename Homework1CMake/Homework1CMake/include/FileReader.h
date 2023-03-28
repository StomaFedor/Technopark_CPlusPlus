#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


class FileReader
{
public:
	std::vector<std::vector<std::string>> ReadFile(std::string filename, const std::vector<size_t>& columns);

private:
	std::vector<std::string> Split(const std::string& str, char separator, const std::vector<size_t>& columns);
};