#include "Level.h"
#include "SLTypes.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "HelperFunctionLibrary.h"

namespace SL
{
	Level::Level() : GameState("unknown") , description(""), choices(0)
	{
	}

	Level::Level(std::string levelName) : GameState(levelName), description(""), choices(0)
	{
		// Open file 
		std::string fileName = "data/level/" + levelName + ".txt"; 
		std::ifstream levelFile(fileName.c_str());
		if (levelFile)
		{
			std::string line; 
			SearchResult res; 

			//TODO : handle condition for description, choices & link 

			// load description 
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[description]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				do
				{
					HelperFunctionLibrary::SLgetline(levelFile, line);

					description += line;
				} while (!line.empty());

			}


			// load choices 
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[choices]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				do
				{
					HelperFunctionLibrary::SLgetline(levelFile, line);

					if(!line.empty())
						choices.push_back(line) ;

				} while (!line.empty());

			}

			// load links 
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[links]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				do
				{
					HelperFunctionLibrary::SLgetline(levelFile, line);

					links.push_back(line);

				} while (!line.empty());

			}

			// check item 
						
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[items]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				HelperFunctionLibrary::SLgetline(levelFile, line);

				std::stringstream lineStream(line); 
				std::string it; 
				while (lineStream >> it)
				{
					items.push_back(it);
				}

			}

			// check progression 

			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[progressions]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				HelperFunctionLibrary::SLgetline(levelFile, line);

				std::stringstream lineStream(line);
				std::string it;
				while (lineStream >> it)
				{
					progressionEvents.push_back(it);
				}

			}

			levelFile.close();
		}

	}

	void Level::Display()
	{

		// check item
		if (!items.empty())
		{
			for (auto item : items)
			{
				OnNewItem.Broadcast(item);
			}
			
		}

		// check progression 
		if (!progressionEvents.empty())
		{
			for (auto progEvent : progressionEvents)
			{
				OnNewProgressionEvent.Broadcast(progEvent);
			}

		}

		// display description 
		std::cout << description << std::endl; 

		HelperFunctionLibrary::SkipLine();

		// display choices 
		HelperFunctionLibrary::DisplayChoices(choices); 
	}

	void Level::HandleInput(int input)
	{
		if (input <= choices.size() && input >= 1)
		{
			std::string nextLevel = links[input-1];

			OnStateEnd.Broadcast<std::string>(nextLevel);
		}

	}
}