#include "GameStateManager.h"
#include <fstream>
#include <memory>
#include "Level.h"

namespace SL
{
	GameStateManager::GameStateManager(GameInstance* p_owingInstance)
	{
		owingInstance = p_owingInstance;
	}

	void GameStateManager::DisplayCurrentState()
	{
		if (!states.empty())
			states.top()->Display();
	}

	void GameStateManager::HandleInput(int input)
	{
		if(!states.empty())
			states.top()->HandleInput(input);
	}

	std::string GameStateManager::GetCurrentStateName()
	{
		return states.top()->GetName();
	}

	void GameStateManager::HandleCurrentStateEnd(std::string nextState )
	{
		if (nextState.empty())
		{
			states.pop();
		}
		else
			LoadNewState<Level>(nextState, true);

	}
}