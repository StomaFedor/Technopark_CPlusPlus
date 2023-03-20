#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileReader
{
public:
	vector<vector<string>> ReadFile(string filename, int firstCol, int secondCol);

private:
	vector<string> Split(string& str, char separator, int firstCol, int secondCol);
};