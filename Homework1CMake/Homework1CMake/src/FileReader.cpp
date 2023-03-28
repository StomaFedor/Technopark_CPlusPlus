#include "FileReader.h"

std::vector<std::vector<std::string>> FileReader::ReadFile(std::string filename, const std::vector<size_t>& columns)
{
    std::vector<std::vector<std::string>> arrData;
    std::string line;
    int i = 0;
    std::ifstream in(filename);
    if (!in.is_open())
        throw std::invalid_argument("The file path is specified incorrectly");
    while (getline(in, line))
    {
        std::vector<std::string> tmp = Split(line, '	', columns);
        if (std::find(tmp.begin(), tmp.end(), "\\N") == tmp.end())
            arrData.push_back(tmp);
    }
    return arrData;
}

std::vector<std::string> FileReader::Split(const std::string& str, char separator, const std::vector<size_t>& columns)
{
    std::vector<std::string> result;
    std::string s;
    int separatorCounter = 0;
    std::stringstream streamData(str);
    while (std::getline(streamData, s, separator)) {
        if (std::find(columns.begin(), columns.end(), separatorCounter) != columns.end())
            result.push_back(s);
        separatorCounter++;
    }
    if (result.size() < columns.size())
        throw std::invalid_argument("Incorrect data in the file");
    return result;
}