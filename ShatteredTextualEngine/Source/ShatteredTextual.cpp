// ShatteredTextual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <iomanip>
#include "HelperFunctionLibrary.h"
#include "GameInstance.h"

namespace fs = std::filesystem;

// return if save already existing 
bool DisplayMenu()
{
	std::string line;
	std::ifstream Icon("Data/Icon.txt");
	while (ST::HelperFunctionLibrary::STgetline(Icon, line))
	{
		std::cout << line << std::endl;
	}

	Icon.close();

	ST::HelperFunctionLibrary::SkipLines(3);

	fs::path savePath("data/save");
	bool bIsSaveFolderNotValid= fs::is_empty(savePath) || !fs::exists(savePath);

	std::vector<std::string> menuChoices;

	if (!bIsSaveFolderNotValid)
	{
		menuChoices.insert(menuChoices.end(), { "Continue","New Game","Quit Game" });
	}
	else
	{
		menuChoices.insert(menuChoices.end(), { "New Game","Quit Game" });
	}

	ST::HelperFunctionLibrary::DisplayChoices(menuChoices);

	return bIsSaveFolderNotValid;
}


int main()
{

	bool bIsSaveFolderEmpty;
	// Display Start Menu (continue, new game, quit game) 
	bIsSaveFolderEmpty = DisplayMenu();

	// Handle input
	int menuInput = ST::HelperFunctionLibrary::GetUserInput(1, bIsSaveFolderEmpty ? 2 : 3);

	if (menuInput == 1 && !bIsSaveFolderEmpty)
	{
		std::cout << "Welcome back !" << std::endl;
		std::cout << "Choose a save slot" << std::endl;

		// Get save STot
		std::string path = "data/save";
		std::vector<std::string> STotNames;
		for (const auto& entry : fs::directory_iterator(path))
		{
			std::string currentString = entry.path().string();
			// erase path part 
			int position = (int)currentString.rfind("\\");
			currentString = currentString.substr((position + 1));
			// erase format 
			position = (int)currentString.rfind(".");
			currentString.erase(position);
			STotNames.push_back(currentString);
		}


		// display save STot 
		ST::HelperFunctionLibrary::DisplayChoices(STotNames);

		//handle input 
		int saveInput = ST::HelperFunctionLibrary::GetUserInput(1, (int)STotNames.size());

		// Launch gameinstance & gameloop 
		ST::GameInstance::Get().Initialize(STotNames[saveInput-1]);
		ST::GameInstance::Get().LoadGame(false);
		ST::GameInstance::Get().GameLoop();

	}
	else if (menuInput == 2 && !bIsSaveFolderEmpty || menuInput == 1 && bIsSaveFolderEmpty)
	{

		std::cout << "Welcome ! What is your name ?" << std::endl;
		std::string name;
		std::cin >> name;
		std::cin.ignore();

		// Launch gameinstance & gameloop 
		ST::GameInstance::Get().Initialize(name);
		ST::GameInstance::Get().LoadGame(true);
		ST::GameInstance::Get().GameLoop();
	}


	return 1; 
}


