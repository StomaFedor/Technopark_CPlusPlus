#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class StatisticsWorker
{
public:
	vector<string> GetArtistListInCurrentYears(vector<vector<string>> artists, int typeId, int beginYear, int EndYear);

	int GetArtistTypeId(vector<vector<string>> types, string artistType);
};