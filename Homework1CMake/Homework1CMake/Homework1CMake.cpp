// Homework1CMake.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <Windows.h>

#include "StatisticsWorker.h"
#include "FileReader.h"

const size_t ARTIST_NAME_COL = 2;
const size_t ARTIST_CREATION_YEAR_COL = 4;
const size_t ARTIST_TYPE_COL = 10;
const size_t ARTISTTYPE_ID_COL = 0;
const size_t ARTISTTYPE_NAME_COL = 1;

void Output(const std::vector<std::string>& groups)
{
    for each (std::string var in groups)
        std::cout << var << std::endl;
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 5)
            throw std::invalid_argument("Incorrect command line data");
        if (std::to_string(std::stoi(argv[3])) != argv[3] || std::to_string(std::stoi(argv[4])) != argv[4])
            throw std::invalid_argument("Incorrectly entered years");
        size_t beginYear = std::stoi(argv[3]), endYear = std::stoi(argv[4]);
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        FileReader reader;
        std::vector<std::vector<std::string>> artists = reader.ReadFile(argv[1], { ARTIST_NAME_COL, ARTIST_CREATION_YEAR_COL, ARTIST_TYPE_COL });
        std::vector<std::vector<std::string>> types = reader.ReadFile(argv[2], { ARTISTTYPE_ID_COL, ARTISTTYPE_NAME_COL });
        StatisticsWorker worker;
        std::string typeId = worker.GetArtistTypeId(types, "Group");
        std::vector<std::string> groups = worker.GetArtistListInCurrentYears(artists, typeId, beginYear, endYear);
        Output(groups);
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
