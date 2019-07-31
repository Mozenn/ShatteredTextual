#pragma once

#include <string> 
#include <memory>
#include "Inventory.h"

struct Progression
{
	bool bFLCompleted = false; 

	bool bFoCompleted = false; 

	bool bAbyssCompleted = false; 

	bool bVillageCompleted = false; 

	bool bCLCompleted = false; 
};

class GameInstance
{

public :

	GameInstance(std::string name, bool bNewGame); 

	~GameInstance();

	void GameLoop(); 

	bool LoadData(); 

	void Save();

	void QuitGame();

private : 

	Progression progression; 

	std::unique_ptr<Inventory> inventory;

	std::string m_name; 

	bool bExitGame; 
};

