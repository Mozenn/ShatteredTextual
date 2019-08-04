#pragma once
#include <string>
#include <vector>

namespace SL
{
	class Inventory
	{
	public:

		void DisplayInventory();

		bool Contains();

		void AddToInventory(std::string newItem);

		void Save();

	private:

		std::vector<std::string> Items;
	};
}



