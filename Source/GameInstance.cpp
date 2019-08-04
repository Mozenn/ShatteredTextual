#include "GameInstance.h"
#include "HelperFunctionLibrary.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "GameStateManager.h"
#include "Level.h"
#include "Save.h"

namespace SL
{
	GameInstance::GameInstance(std::string name) : bExitGame(false), m_name(name)
	{
		InitializeProgression();
	}

	void GameInstance::GameLoop()
	{
		while (!bExitGame)
		{
			HelperFunctionLibrary::SkipLine();

			HelperFunctionLibrary::DisplayLine();

			HelperFunctionLibrary::SkipLine();

			// Display HUD (Save, see inventory, quit game)  
			void DisplayHUD();

			// Display Level (description & choices) 
			levelManager->DisplayCurrentState();
			// Wait for input 
			levelManager->HandleInput();
		}
	}

	void GameInstance::InitializeProgression()
	{
		// TODO 
	}

	bool GameInstance::LoadGame(bool bNewGame)
	{
		if (bNewGame)
		{
			levelManager = std::make_unique<GameStateManager>();
			levelManager->Initialize<Level>();
		}
		else
		{
			// open save file 
			std::ifstream saveFile("data/save/" + m_name);

			if (!saveFile)
			{
				return false;
			}

			std::string line;
			SearchResult res;

			// load progression 
			res = HelperFunctionLibrary::GetPositionInFile(saveFile, "[progression]");
			if (res.bFound)
			{


			}

			// load & set current level 
			std::string currentLevel;

			levelManager = std::make_unique<GameStateManager>();
			levelManager->Initialize<Level>(currentLevel);

			// load inventory
		}

	}

	void GameInstance::SaveGame() // TODO 
	{
		std::string saveFileName = "data/save/" + m_name + ".txt";
		std::ofstream saveFile(saveFileName.c_str());

		if (saveFile)
		{
			// save current level 
			saveFile << levelManager->GetCurrentStateName() << std::endl; 
			// save inventory 
			inventory->Save();

			// save progression 

		}
	}

	void GameInstance::DisplayHUD()
	{
		HelperFunctionLibrary::SkipLine();
		std::cout << "7. inventory  ||  8. save || 9. quit" << std::endl; 
		HelperFunctionLibrary::SkipLine();
	}
	
	void GameInstance::QuitGame()
	{
		bExitGame = true; 
	}
}

