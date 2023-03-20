// homework_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>

#include "FileReader.h"
#include "StatisticsWorker.h"

class MyException : public std::exception
{
private:
    std::string m_error;

public:
    MyException(std::string error)
        : m_error(error)
    {
    }

    const char* what() const noexcept
    {
        return m_error.c_str();
    }
};

void Output(vector<string> groups);

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 5)
            throw new invalid_argument("Incorrect command line data");
        if (to_string(atoi(argv[3])) != argv[3] || to_string(atoi(argv[4])) != argv[4])
            throw new invalid_argument("Incorrectly entered years");
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

void Output(vector<string> groups)
{
    for (int i = 0; i < groups.size(); ++i)
        cout << groups[i] << endl;
}
