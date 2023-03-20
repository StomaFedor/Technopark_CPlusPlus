#include "FileReader.h"

vector<vector<string>> FileReader::ReadFile(string filename, int firstCol, int secondCol)
{
    vector<vector<string>> arrData;
    string line;
    int i = 0;
    ifstream in(filename);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            vector<string> tmp = Split(line, '	', firstCol, secondCol);
            if (tmp[1] != "\\N")
                arrData.push_back(tmp);
        }
    }
    else
        throw new invalid_argument("The file path is specified incorrectly");
    in.close();
    return arrData;
}

vector<string> FileReader::Split(string& str, char separator, int firstCol, int secondCol)
{
    vector<string> result;
    string s;
    int separatorCounter = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != separator) {
            s += str[i];
        }
        else if (firstCol == separatorCounter || secondCol == separatorCounter) {
            result.push_back(s);
            s.clear();
            separatorCounter++;
        }
        else {
            s.clear();
            separatorCounter++;
        }
    }
    return result;
}