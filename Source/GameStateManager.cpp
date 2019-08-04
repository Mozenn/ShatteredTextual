#include "GameStateManager.h"
#include <fstream>
#include <memory>

namespace SL
{
	GameStateManager::GameStateManager()
	{
	}

	void GameStateManager::DisplayCurrentState()
	{
		if (!states.empty())
			states.top()->Display();
	}

	void GameStateManager::HandleInput()
	{
		if(!states.empty())
			states.top()->HandleInput();
	}

	std::string GameStateManager::GetCurrentStateName()
	{
		return states.top()->GetName();
	}
}