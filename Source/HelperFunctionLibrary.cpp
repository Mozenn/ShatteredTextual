#include "HelperFunctionLibrary.h"
#include <iostream>
#include "SLTypes.h"

namespace SL
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

	SearchResult HelperFunctionLibrary::GetPositionInFile(std::istream& file, std::string search)
	{
		if (file)
		{
			std::string line;
			bool found = false;

			file.seekg(0, file.beg);

			getline(file, line);

			while (!line.empty() || found)
			{
				if (line.find(search) == std::string::npos)
				{
					found = true;

					return SearchResult(file.tellg(),found);
				}
			}

			return SearchResult(std::streampos(),found);

		}

		return SearchResult(std::streampos(), false);
	}

}