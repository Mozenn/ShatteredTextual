#pragma once

#include <string>
#include <vector>
#include "GameState.h"

namespace SL
{
	class Level : public GameState
	{
	public:

		Level();

		Level(std::string levelName);

		virtual void Display() override;

		virtual void HandleInput() override;

		// event OnNewItem
		//event OnNewProgression 

	private :

		std::string description; 

		std::vector<std::string> choices;

		// Link levels to choices 
		std::vector<std::string> links;

	};

}


