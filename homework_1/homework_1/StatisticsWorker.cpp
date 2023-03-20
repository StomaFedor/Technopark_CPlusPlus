#include "StatisticsWorker.h"

vector<string> StatisticsWorker::GetArtistListInCurrentYears(vector<vector<string>> artists, int typeId, int beginYear, int EndYear)
{
	vector<string> result;
	for (int i = 0; i < artists.size(); ++i)
		if (beginYear < stoi(artists[i][1]) && EndYear > stoi(artists[i][1]))
			result.push_back(artists[i][0]);
	return result;
}

int StatisticsWorker::GetArtistTypeId(vector<vector<string>> types, string artistType)
{
	int i = 0;
	for (i = 0; i < types.size(); ++i)
		if (types[i][1] == artistType)
			break;
	return stoi(types[i][0]);
}
