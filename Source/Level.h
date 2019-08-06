#pragma once

#include <string>
#include <vector>
#include "GameState.h"
#include "Event.h"
#

namespace SL
{
	class Level : public GameState
	{
	public:

		Level();

		Level(std::string levelName);

		Event<void(std::string)> OnNewItem; 

		Event<void(std::string)> OnNewProgressionEvent;

		virtual void Display() override;

		virtual void HandleInput(int input) override;

	private :

		std::string description; 

		std::vector<std::string> choices;

		// Link levels to choices 
		std::vector<std::string> links;

	};

}


