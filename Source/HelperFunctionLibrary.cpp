#include "HelperFunctionLibrary.h"
#include <iostream>

void HelperFunctionLibrary::SkipLine()
{
	std::cout << std::endl;
}

void HelperFunctionLibrary::SkipLines(int const& n)
{
	for (int i(0); i < n; i++)
	{
		std::cout << std::endl;
	}
}

void HelperFunctionLibrary::DisplayLine()
{
	std::cout << "--------------------------------------------" << std::endl;
}

void HelperFunctionLibrary::MakeGap(int const& n)
{
	for (int i(0); i < n; i++)
	{
		std::cout << " ";
	}
}

void HelperFunctionLibrary::DisplayChoices(std::vector<std::string> const&  choices)
{
	for (unsigned i(0); i < choices.size(); i++)
	{
		std::cout << i + 1 << " " << choices[i] << std::endl;
	}
}

int HelperFunctionLibrary::GetUserInput(int const& min, int const& max)
{
	bool bInputOK = false; 
	int input;

	while (!bInputOK)
	{
		std::cin >> input; 
		std::cin.ignore();

		if (input >= min && input <= max)
		{
			bInputOK = true;
		}
		else
			std::cout << "Wrong Input" << std::endl; 
	}

	return input; 
}