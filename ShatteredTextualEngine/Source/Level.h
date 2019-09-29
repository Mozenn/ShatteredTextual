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
		/* throw WrongLevelName  */
		Level(std::string levelName);

		/* Event called on level entrance if level contains an item */
		Event<void(std::string)> OnNewItem; 

		/* Event called on level entrance if level contains a progresion event */
		Event<void(std::string)> OnNewProgressionEvent;

		virtual void Display() override;

		virtual void HandleInput(int input) override;

	private :

		std::string description; 

		std::vector<std::string> choices;

		std::vector<std::string> items;

		std::vector<std::string> progressionEvents;

		/* 
		Link levels to choices 
		Contains next level name for each choice 
		*/ 
		std::vector<std::string> links;

	};

}


