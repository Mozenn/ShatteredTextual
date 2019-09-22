#pragma once
#include <string>
#include <vector>
#include "Save.h"

namespace ST
{
	class Save;

	class Inventory
	{
	public:

		void DisplayInventory();

		void AddToInventory(std::string newItem);

		void Save(Save& save);

		void Load(ST::Save& save);

		bool Contains(std::string item);

	private:

		std::vector<std::string> items;
	};
}



