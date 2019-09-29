#include "HelperFunctionLibrary.h"
#include <iostream>
#include "STTypes.h"

namespace ST
{

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

	void HelperFunctionLibrary::DisplayChoices(std::vector<std::string> const& choices)
	{
		for (unsigned i(0); i < choices.size(); i++)
		{
			std::cout << i + 1 << ". " << choices[i] << std::endl;
		}
		SkipLine();
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
			{
				std::cout << "Wrong Input" << std::endl;
			}

		}

		return input;
	}

	int HelperFunctionLibrary::GetUserInput(const std::vector<std::pair<int, int>>& validRanges)
	{
		bool bInputOK = false;
		int input;
		
		while (!bInputOK)
		{
			std::cin >> input;
			std::cin.ignore();

			for (auto it : validRanges)
			{
				if (input >= it.first && input <= it.second)
				{
					bInputOK = true;
				}
			}

			if(!bInputOK)
				std::cout << "Wrong Input" << std::endl;
		}

		return input;
	}

	SearchResult HelperFunctionLibrary::GetPositionInFile(std::istream& file, std::string search)
	{
		if (file)
		{
			std::string line;
			bool found = false;

			file.seekg(0, file.beg);

			HelperFunctionLibrary::STgetline(file, line);

			while (line != "*" && !found)
			{
				if (line.find(search) != std::string::npos)
				{
					found = true;

					return SearchResult(file.tellg(),found);
				}
				HelperFunctionLibrary::STgetline(file, line);
			}

			return SearchResult(std::streampos(),found);

		}

		return SearchResult(std::streampos(), false);
	}

	std::istream& HelperFunctionLibrary::STgetline(std::istream& is, std::string& str)
	{
		bool bIsValid = false; 
		

		while (!bIsValid && getline(is, str))
		{
			if (str.substr(0, 2) != "//")
			{
				bIsValid = true;
			}
			else
			{
				str.clear();
			}
				
		}

		return is;
	}

}