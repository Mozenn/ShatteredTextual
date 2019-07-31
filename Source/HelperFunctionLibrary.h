#pragma once

#include <vector>
#include <string>

class HelperFunctionLibrary
{

public :

	static void SkipLine();

	static void SkipLines(int const& n);

	static void DisplayLine();

	static void MakeGap(int const& n);

	static void DisplayChoices(std::vector<std::string> const& choices);

	static int GetUserInput(int const& min, int const&  max);

};

