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

		/* Save local member to given save object instance */
		void Save(Save& save);

		/* Save local member from given save object instance */
		void Load(ST::Save& save);

		/* check if inventory contains item */
		bool Contains(std::string item);

	private:

		std::vector<std::string> items;
	};
}



