#pragma once
#include <string>
#include <vector>
#include <map>

namespace ST
{
	// class containing every data needed to be saved 
	class Save
	{
	public:

		Save(std::string name);

		std::string currentLevel;

		std::vector<std::string> items;

		std::map<std::string, int> progression;

		void SaveSlot();

		bool LoadSlot();

	private:

		std::string saveName= "none" ;
	};

}