#pragma once
#include <string>
#include <vector>
#include "Save.h"

namespace SL
{
	class Save;

	class Inventory
	{
	public:

		Inventory(); 

		void DisplayInventory();

		void AddToInventory(std::string newItem);

		void Save(Save& save);

		void Load(SL::Save& save);

	private:

		std::vector<std::string> items;
	};
}



