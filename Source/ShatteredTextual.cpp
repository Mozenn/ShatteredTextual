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

namespace fs = std::experimental::filesystem;

// return if save already existing 
bool DisplayMenu()
{

	std::string line;
	std::ifstream Icon("Data/Icon.txt");
	while (SL::HelperFunctionLibrary::SLgetline(Icon, line))
	{
		std::cout << line << std::endl;
	}

	Icon.close();

	SL::HelperFunctionLibrary::SkipLines(3);

	fs::path savePath("data/save");
	bool bIsSaveFolderEmpty = fs::is_empty(savePath);

	std::vector<std::string> menuChoices;

	if (!bIsSaveFolderEmpty)
	{
		menuChoices.insert(menuChoices.end(), { "Continue","New Game","Quit Game" });
	}
	else
	{
		menuChoices.insert(menuChoices.end(), { "New Game","Quit Game" });
	}

	SL::HelperFunctionLibrary::DisplayChoices(menuChoices);

	return bIsSaveFolderEmpty;
}


int main()
{

	bool bIsSaveFolderEmpty;
	// Display Start Menu (continue, new game, quit game) 
	bIsSaveFolderEmpty = DisplayMenu();

	// Handle input
	int menuInput = SL::HelperFunctionLibrary::GetUserInput(1, bIsSaveFolderEmpty ? 2 : 3);

	if (menuInput == 1 && !bIsSaveFolderEmpty)
	{
		std::cout << "Welcome back adventurer !" << std::endl;
		std::cout << "Choose a save slot" << std::endl;

		// Get save slot
		std::string path = "data/save";
		std::vector<std::string> slotNames;
		for (const auto& entry : fs::directory_iterator(path))
		{
			std::string currentString = entry.path().string();
			// erase path part 
			int position = (int)currentString.rfind("\\");
			currentString = currentString.substr((position + 1));
			// erase format 
			position = (int)currentString.rfind(".");
			currentString.erase(position);
			slotNames.push_back(currentString);
		}


		// display save slot 
		SL::HelperFunctionLibrary::DisplayChoices(slotNames);

		//handle input 
		int saveInput = SL::HelperFunctionLibrary::GetUserInput(1, (int)slotNames.size());

		// Launch gameinstance & gameloop 
		SL::GameInstance::Get().Initialize(slotNames[saveInput]);
		SL::GameInstance::Get().LoadGame(false);
		SL::GameInstance::Get().GameLoop();

	}
	else if (menuInput == 2 && !bIsSaveFolderEmpty || menuInput == 1 && bIsSaveFolderEmpty)
	{

		std::cout << "Welcome adventurer ! What is your name ?" << std::endl;
		std::string name;
		std::cin >> name;
		std::cin.ignore();

		// Launch gameinstance & gameloop 
		SL::GameInstance::Get().Initialize(name);
		SL::GameInstance::Get().LoadGame(true);
		SL::GameInstance::Get().GameLoop();
	}


	return 1; 
}


