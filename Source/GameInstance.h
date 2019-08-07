#pragma once

#include <string> 
#include <memory>
#include "Inventory.h"
#include <map>
//#include "GameStateManager.h"


namespace SL
{
	class Save;

	class GameStateManager; 

	class GameInstance
	{

	public:

		static GameInstance& Get()
		{
			static GameInstance* instance = new GameInstance();
			return *instance;
		}

		void Initialize(std::string name);

		void GameLoop();

		bool LoadGame(bool bNewGame);

		void SaveGame();

		void QuitGame();

		void DisplayHUD();

		void DisplayInventory();

		void HandleOnNewItem(std::string newItem); 

		void HandleOnNewProgressionEvent(std::string newProg);

	private:

		GameInstance();

		std::map<std::string,int> progression;

		std::unique_ptr<Inventory> inventory;

		std::string m_name;

		bool bExitGame;

		std::unique_ptr<GameStateManager> levelManager;

		std::shared_ptr<Save> save;

		void InitializeProgression();

		void LocalSave();

		void HandleInput();
	};
}



