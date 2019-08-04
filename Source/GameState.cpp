#include "GameState.h"

namespace SL
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
}