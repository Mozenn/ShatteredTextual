#pragma once

#include <string>
#include <vector>
#include "GameState.h"
#include "Event.h"

namespace ST
{
	class Level : public GameState
	{
	public:

		Level();
		~Level() = default;
		Level(const Level&) = default;
		Level& operator=(const Level&) = default;
		Level(Level&&) = default;
		Level& operator=(Level&&) = default;

		Level(std::string levelName);

		Event<void(std::string)> OnNewItem; 

		Event<void(std::string)> OnNewProgressionEvent;

		virtual void Display() override;

		virtual void HandleInput(int input) override;

	private :

		std::string description; 

		std::vector<std::string> choices;

		std::vector<std::string> items;

		std::vector<std::string> progressionEvents;

		// Link levels to choices 
		std::vector<std::string> links;

	};

}


