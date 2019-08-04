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


			// load description 
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[description]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				do
				{
					getline(levelFile, line);

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
					getline(levelFile, line);

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
					getline(levelFile, line);

					choices.push_back(line);

				} while (!line.empty());

			}

			// check item 
						
			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[items]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				getline(levelFile, line);

				std::stringstream lineStream(line); 
				std::string it; 
				while (lineStream >> it)
				{
					// TODO call OnNewItem
				}

			}

			// check progression 

			res = HelperFunctionLibrary::GetPositionInFile(levelFile, "[progressions]");
			if (res.bFound)
			{
				levelFile.seekg(res.position);

				getline(levelFile, line);

				std::stringstream lineStream(line);
				std::string it;
				while (lineStream >> it)
				{
					// TODO call OnNewProgression
				}

			}
		}

	}

	void Level::Display()
	{

		// display description 
		std::cout << description << std::endl; 

		// display choices 
		HelperFunctionLibrary::DisplayChoices(choices); 
	}

	void Level::HandleInput()
	{
		//wait for input 
		int input = HelperFunctionLibrary::GetUserInput(1, (int)choices.size());

		std::string nextLevel = links[input]; 

		// TODO : call onChangedLevel()
	}
}