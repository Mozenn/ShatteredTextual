#include "GameState.h"

namespace ST
{
	GameState::GameState()
	{

	}
	GameState::GameState(std::string p_name) : name(p_name)
	{

	}

	std::string GameState::GetName() const
	{
		return name; 
	}

	bool GameState::IsEqual(GameState const& B) const 
	{
		return name == B.name; 
	}

	bool operator==(GameState const& A, GameState const& B)
	{
		return A.IsEqual(B);
	}
}