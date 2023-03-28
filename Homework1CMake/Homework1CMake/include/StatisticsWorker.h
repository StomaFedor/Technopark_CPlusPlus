#pragma once
#include <vector>
#include <string>
#include <iostream>

const size_t TYPE_NAME = 1;
const size_t TYPE_ID = 0;
const size_t ARTIST_NAME = 0;
const size_t ARTIST_YEAR = 1;
const size_t ARTIST_TYPE = 2;

class StatisticsWorker
{
public:
	std::vector<std::string> GetArtistListInCurrentYears(std::vector<std::vector<std::string>> artists, std::string typeId, int beginYear, int endYear);

	std::string GetArtistTypeId(const std::vector<std::vector<std::string>>& types, const std::string& artistType);
};