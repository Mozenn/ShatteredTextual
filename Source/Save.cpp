#include "Save.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "SLTypes.h"
#include "HelperFunctionLibrary.h"

namespace SL
{ 

	Save::Save() : saveName("none")
	{

	}

	Save::Save(std::string name) : saveName(name)
	{

	}

	void Save::SaveSlot()
	{
		std::string saveFileName = "data/save/" + saveName + ".txt";
		std::ofstream saveFile(saveFileName.c_str());

		if (saveFile)
		{
			// save current level 
			saveFile << currentLevel << std::endl;
			// save inventory 
			for (auto it : items)
			{
				saveFile << it << " "; 
			}
			saveFile << std::endl;

			// save progression 
			for (auto progIt : progression)
			{
				saveFile << progIt.first + " " + std::to_string(progIt.second) + " "; 
			}
		}
	}

	bool Save::LoadSlot()
	{
		std::string line;
		SearchResult res;

		std::string saveName = "data/save/" + saveName + ".txt";
		std::ifstream saveFile(saveName.c_str());

		if(saveFile)
		{
			// load current level 
			HelperFunctionLibrary::SLgetline(saveFile, line);

			currentLevel = line;

			// load inventory
			HelperFunctionLibrary::SLgetline(saveFile, line);

			std::stringstream itemStream(line);
			std::string item ;
			while (itemStream >> item)
			{
				items.push_back(item);
			}

			// load progression 
			HelperFunctionLibrary::SLgetline(saveFile, line);

			std::stringstream progStream(line);
			std::string prog, bit;
			while (progStream >> prog)
			{
				progStream >> bit;
				progression[prog] = std::atoi(bit.c_str()); 
			}



			saveFile.close();

			return true; 
		}

		return false; 
	}
}
