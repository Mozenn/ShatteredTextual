#pragma once
#include <string>
#include "Event.h"

namespace ST
{
	class GameState
	{
	public:

		/* Assign name only */
		GameState(std::string p_name);

		virtual ~GameState()=default ;

		/* 
		Event called when state end 
		Take next level name or "" if no next level 
		*/
		Event<void(std::string)> OnStateEnd; 

		/* 
		Called every loop 
		Display desired state information to player 
		*/
		virtual void Display() = 0;

		/*
		Called every loop 
		*/
		virtual void HandleInput(int input) = 0;

		std::string GetName() const ; 

		/* Used for operator == */ 
		bool IsEqual(GameState const& B) const;

	protected :

		std::string name; 

	};

	bool operator==(GameState const& A, GameState const& B);

}

