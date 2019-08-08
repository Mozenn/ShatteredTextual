#pragma once
#include <istream>

namespace ST
{
	struct SearchResult
	{
		SearchResult() : position(std::streampos()), bFound(false)
		{}

		SearchResult(std::streampos p_position, bool p_bFound) : position(p_position), bFound(p_bFound)
		{}

		std::streampos position;

		bool bFound;
	};
}

