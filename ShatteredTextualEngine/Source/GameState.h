#pragma once
#include <string>
#include "Event.h"

namespace ST
{
	class GameState
	{
	public:

		GameState(std::string p_name);

		~GameState()=default ;

		Event<void(std::string)> OnStateEnd; 

		virtual void Display() = 0;

		virtual void HandleInput(int input) = 0;

		std::string GetName() const ; 

		bool IsEqual(GameState const& B) const;

	protected :

		std::string name; 

	};

	bool operator==(GameState const& A, GameState const& B);

}

