#pragma once
#include <string>

namespace SL
{
	class GameState
	{
	public:
		GameState();

		GameState(std::string p_name);

		virtual void Display() = 0;

		virtual void HandleInput() = 0;

		std::string GetName() const; 

	protected :

		std::string name; 

	};

}

