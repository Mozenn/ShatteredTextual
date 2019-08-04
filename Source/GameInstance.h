#pragma once

#include <string> 
#include <memory>
#include "Inventory.h"
#include <map>
#include "GameStateManager.h"


namespace SL
{
	class Save;

	class GameInstance
	{

	public:

		GameInstance(std::string name);

		void GameLoop();

		bool LoadGame(bool bNewGame);

		void SaveGame();

		void QuitGame();

		void DisplayHUD();

	private:

		std::map<std::string,int> progression;

		std::unique_ptr<Inventory> inventory;

		std::string m_name;

		bool bExitGame;

		std::unique_ptr<GameStateManager> levelManager;

		//Save save;

		void InitializeProgression();
	};
}



