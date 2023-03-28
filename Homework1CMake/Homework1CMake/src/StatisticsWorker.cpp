#include "StatisticsWorker.h"

std::vector<std::string> StatisticsWorker::GetArtistListInCurrentYears(std::vector<std::vector<std::string>> artists, std::string typeId, int beginYear, int endYear)
{
	std::vector<std::string> result;
	for each (std::vector<std::string> artist in artists)
		if (typeId == artist[ARTIST_TYPE] && beginYear < std::stoi(artist[ARTIST_YEAR]) && endYear > std::stoi(artist[ARTIST_YEAR]))
			result.push_back(artist[ARTIST_NAME]);
	return result;
}

std::string StatisticsWorker::GetArtistTypeId(const std::vector<std::vector<std::string>>& types, const std::string& artistType)
{
	int i = 0;
	for each (std::vector<std::string> type in types)
		if (type[TYPE_NAME] == artistType)
			return type[TYPE_ID];
}
