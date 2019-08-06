#include "GameInstance.h"
#include "HelperFunctionLibrary.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include "GameStateManager.h"
#include "Level.h"
#include "Save.h"
#include "InventoryMenu.h"
#include <algorithm>

namespace SL
{
	GameInstance::GameInstance() : bExitGame(false)
	{
		InitializeProgression();
	}

	void GameInstance::Initialize(std::string name)
	{
		m_name = name;
		save = std::make_shared<Save>(name);
	}

	void GameInstance::GameLoop()
	{
		while (!bExitGame)
		{
			HelperFunctionLibrary::SkipLine();

			HelperFunctionLibrary::DisplayLine();

			HelperFunctionLibrary::SkipLine();

			// Display HUD (Save, see inventory, quit game)  
			DisplayHUD();

			// Display Level (description & choices) 
			levelManager->DisplayCurrentState();
			// Handle Input for input 
			HandleInput();
		}
	}

	void GameInstance::HandleInput()
	{
		int input = HelperFunctionLibrary::GetUserInput(1,9);

		switch (input)
		{
		case 7:
		{
			levelManager->LoadNewState<InventoryMenu>("inventoryMenu", false); 
			break;
		}
		case 8:
		{
			SaveGame();
			break;
		}
		case 9:
		{
			QuitGame();
			break;
		}
		default:
		{
			levelManager->HandleInput(input);
		}
		}
	}

	void GameInstance::InitializeProgression()
	{
		// loop the data/progression and fill the map with all data with stringstream 

		std::string fileName = "data/progressionEventList.txt" ;
		std::ifstream File(fileName.c_str());

		if (File)
		{

			std::string line; 
			HelperFunctionLibrary::SLgetline(File, line);

			std::stringstream lineStream(line);
			std::string prog, bit;
			while (lineStream >> prog)
			{
				progression[prog] = 0;
			}

			File.close();
		}
	}

	void GameInstance::HandleOnNewItem(std::string newItem)
	{
		inventory->AddToInventory(newItem);
	}

	void GameInstance::HandleOnNewProgressionEvent(std::string newProg)
	{
		if (progression.find(newProg) != progression.end())
		{
			progression[newProg] = 1; 
		}
		
	}

	bool GameInstance::LoadGame(bool bNewGame)
	{
		if (bNewGame)
		{
			levelManager = std::make_unique<GameStateManager>(this);
			levelManager->Initialize<Level>();
		}
		else
		{
			save->LoadSlot();

			levelManager = std::make_unique<GameStateManager>(this);
			levelManager->Initialize<Level>(save->currentLevel);

			inventory->Load(*save);

			progression = save->progression;

		}

		return true; 
	}

	void GameInstance::SaveGame() 
	{
		LocalSave();

		inventory->Save(*save);

		save->SaveSlot();
	}

	void GameInstance::DisplayHUD()
	{
		HelperFunctionLibrary::SkipLine();
		std::cout << "7. inventory  ||  8. save || 9. quit" << std::endl; 
		HelperFunctionLibrary::SkipLine();
	}

	void GameInstance::DisplayInventory()
	{
		inventory->DisplayInventory();
	}
	
	void GameInstance::QuitGame()
	{
		bExitGame = true; 
	}

	void GameInstance::LocalSave()
	{
		save->currentLevel = levelManager->GetCurrentStateName();

		save->progression = progression; 
	}
}
