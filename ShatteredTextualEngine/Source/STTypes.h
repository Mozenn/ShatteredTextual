#pragma once
#include <istream>

/* Header containing global custom types used globaly in the engine */

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

