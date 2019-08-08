#pragma once

#include <vector>
#include <string>
#include "STTypes.h"
#include <istream>

namespace ST
{

	class HelperFunctionLibrary
	{

	public:

		static void SkipLine();

		static void SkipLines(int const& n);

		static void DisplayLine();

		static void MakeGap(int const& n);

		static void DisplayChoices(std::vector<std::string> const& choices);

		static int GetUserInput(int const& min, int const& max);

		static int GetUserInput(std::vector<std::pair<int, int>>& validRanges);

		static SearchResult GetPositionInFile(std::istream& file, std::string search);

		// simple getline but ignore commented line with "//" 
		static std::istream& STgetline(std::istream& is, std::string& str);

	};

}