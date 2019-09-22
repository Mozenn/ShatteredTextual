#include "Level.h"
#include "STTypes.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "HelperFunctionLibrary.h"
#include "GameInstance.h"
#include <ctime>
#include "WrongLevelName.h"

namespace ST
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
					HelperFunctionLibrary::STgetline(levelFile, line);

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
					HelperFunctionLibrary::STgetline(levelFile, line);

					if (!line.empty())
					{
						choices.push_back(line);
					}
						

				} while (!line.empty());

			}

			// load links 
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[links]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				do
				{
					HelperFunctionLibrary::STgetline(levelFile, line);

					size_t pos = line.find(":"); 

					if (pos != std::string::npos)
					{
						std::string condition, link, conditionType;
						std::string conditions = line.substr(pos+(size_t)1);
						std::string tempLinks = line.substr(0, pos);

						std::stringstream linksStream(tempLinks);
						std::stringstream conditionsStream(conditions);
						bool bDone = false; 
						while (linksStream >> link && conditionsStream >> conditionType && conditionsStream >> condition && !bDone)
						{
							if (conditionType == "." || condition == "...")
							{
								links.push_back(link);
								bDone = true; 
							}
							else if (conditionType == "I" && GameInstance::Get().CheckItem(condition))
							{
								links.push_back(link);
								bDone = true;
							}
							else if (conditionType == "P" && GameInstance::Get().CheckProgEvent(condition))
							{
								links.push_back(link);
								bDone = true;
							}
							else if (conditionType == "R" )
							{
								srand(time(0));

								float rand(rand() % 100);
								rand /= 100; 
								if (rand <= std::stof(condition))
								{
									links.push_back(link);
									bDone = true;
								}

							}
						}


					}
					else
					{
						links.push_back(line);
					}

				} while (!line.empty());

			}

			// check item 
						
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[items]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				HelperFunctionLibrary::STgetline(levelFile, line);

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

				HelperFunctionLibrary::STgetline(levelFile, line);

				std::stringstream lineStream(line);
				std::string it;
				while (lineStream >> it)
				{
					progressionEvents.push_back(it);
				}

			}

			levelFile.close();
		}
		else
		{
			throw WrongLevelName();
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