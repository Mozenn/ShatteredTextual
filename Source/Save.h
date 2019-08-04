#pragma once
#include <string>
#include <vector>
#include <map>

namespace SL
{
	// class containing every data needed to be saved 
	class Save
	{
		public : 

			std::string currentLevel; 

			std::vector<std::string> items;

			std::map<std::string, int> progression;

			//void SaveGame();
	};

}