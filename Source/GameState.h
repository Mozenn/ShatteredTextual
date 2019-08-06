#pragma once
#include <string>
#include "Event.h"

namespace SL
{
	class GameState
	{
	public:
		GameState();

		GameState(std::string p_name);

		Event<void(std::string)> OnStateEnd; 

		virtual void Display() = 0;

		virtual void HandleInput(int input) = 0;

		std::string GetName() const; 

	protected :

		std::string name; 

	};

}

