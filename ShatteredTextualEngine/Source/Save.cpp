#include "Save.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "STTypes.h"
#include "HelperFunctionLibrary.h"

namespace ST
{ 

	Save::Save() : saveName("none")
	{

	}

	Save::Save(std::string name) : saveName(name)
	{

	}

	void Save::SaveSlot()
	{
		std::string saveFileName = "data/save/" + saveName + ".sav";
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

		std::string tempSaveName = "data/save/" + saveName + ".sav";
		std::ifstream saveFile(tempSaveName.c_str());

		if(saveFile)
		{
			// load current level 
			HelperFunctionLibrary::STgetline(saveFile, line);

			currentLevel = line;

			// load inventory
			HelperFunctionLibrary::STgetline(saveFile, line);

			std::stringstream itemStream(line);
			std::string item ;
			while (itemStream >> item)
			{
				items.push_back(item);
			}

			// load progression 
			HelperFunctionLibrary::STgetline(saveFile, line);

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
