#pragma once

#include <string> 
#include <memory>
#include "Inventory.h"
#include <map>


namespace ST
{
	// Forward declarations 
	class Save;
	class GameStateManager; 

	class GameInstance
	{

	public:

		// TODO : replace singleton by better design ( DI or Service locator ) 

		// static get, part of singleton pattern 
		static GameInstance& Get()
		{
			static GameInstance* instance = new GameInstance();
			return *instance;
		}

		// rule of five  

		// initialize name & save 
		void Initialize(std::string name);

		// Main gameloop 
		void GameLoop();

		// Initialize levelManager & load data from save slot 
		bool LoadGame(bool bNewGame);

		// Save all data to save object member then save to slot file 
		void SaveGame();

		// exit GameLoop
		void QuitGame();

		void DisplayHUD();

		void DisplayInventory();

		// Check if item is in inventory 
		bool CheckItem(std::string item) const ; 

		// Check if progression event has been encountered 
		bool CheckProgEvent(std::string progEvent) const;

		// called when new item found in new loaded level
		// bound to OnNewItem event of current level in LevelManager 
		void HandleOnNewItem(std::string newItem); 

		// called when new progression event found in new loaded level
		// bound to OnNewProgressionEvent event of current level in LevelManager 
		void HandleOnNewProgressionEvent(std::string newProg);

	private:

		GameInstance();

		std::map<std::string,int> progression;

		std::unique_ptr<Inventory> inventory;

		std::string m_name;

		bool bExitGame;

		std::unique_ptr<GameStateManager> levelManager;

		std::shared_ptr<Save> save;

		// loop through progression file to fill progression vector 
		void InitializeProgression();

		virtual bool ShouldExitGame(); // override or modify this function to implement custom exit of game loop 

		void LocalSave();

		void HandleInput();
	};
}



