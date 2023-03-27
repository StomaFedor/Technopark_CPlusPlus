// Homework1CMake.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <Windows.h>

#include "StatisticsWorker.h"
#include "FileReader.h"

void Output(vector<string> groups)
{
    for (int i = 0; i < groups.size(); ++i)
        cout << groups[i] << endl;
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 5)
            throw invalid_argument("Incorrect command line data");
        if (to_string(atoi(argv[3])) != argv[3] || to_string(atoi(argv[4])) != argv[4])
            throw invalid_argument("Incorrectly entered years");
        int beginYear = atoi(argv[3]), endYear = atoi(argv[4]);
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        FileReader reader;
        vector<vector<string>> artists = reader.ReadFile(argv[1], 2, 4);
        vector<vector<string>> types = reader.ReadFile(argv[2], 0, 1);
        StatisticsWorker worker;
        int typeId = worker.GetArtistTypeId(types, "Group");
        vector<string> groups = worker.GetArtistListInCurrentYears(artists, typeId, beginYear, endYear);
        Output(groups);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
}
