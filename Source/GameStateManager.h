#pragma once

#include "GameState.h"
#include <stack>
#include <memory>
#include <string>

namespace SL
{
	using StateRef = std::shared_ptr<GameState>;

	class GameStateManager
	{
	public:

		GameStateManager();

		template<class T>
		void Initialize(std::string startState = "CaveStart")
		{
			StateRef newState = std::make_shared<T>(startState);

			states.push(newState);
		}

		void DisplayCurrentState();

		template<class T>
		void LoadNewState(std::string stateName, bool isReplacing)
		{
			if (isReplacing && !states.empty())
				states.pop();

			StateRef newState = std::make_shared<T>(stateName);

			states.push(newState);
		}

		void HandleInput();

		template<class T>
		void HandleCurrentStateEnd(std::string nextState)
		{
			LoadNewState<T>(nextState, true);

		}

		std::string GetCurrentStateName(); 

	protected:

		std::stack<StateRef> states;
	};
}



