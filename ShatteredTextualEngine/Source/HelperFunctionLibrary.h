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

		/*  */
		static void SkipLine();

		static void SkipLines(int const& n);

		/* 
		Display a line full of "-" 
		Use as separator to organize code 
		*/
		static void DisplayLine();

		/* display " " n time */
		static void MakeGap(int const& n);

		/* 
		Display given choices in a structured way 
		Choices are numbered 
		*/
		static void DisplayChoices( std::vector<std::string> const& choices);

		/* Wrap a cin operation accepting only integer input in min-max range  */
		static int GetUserInput(int const& min, int const& max);

		/* Wrap a cin operation accepting only integer input in min-max range  */
		static int GetUserInput(std::vector<std::pair<int, int>> const & validRanges);

		/* Return position in file of given string */
		static SearchResult GetPositionInFile(std::istream& file, std::string search);

		/* simple getline but ignore commented line with "//" */
		static std::istream& STgetline(std::istream& is, std::string& str);

	};

}