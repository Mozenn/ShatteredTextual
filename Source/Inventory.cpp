#include "Inventory.h"
#include "Save.h"
#include "HelperFunctionLibrary.h"
#include <iostream>
#include <algorithm>

namespace ST
{

	Inventory::Inventory()
	{
	}

	void Inventory::DisplayInventory()
	{
		HelperFunctionLibrary::SkipLine();

		for (auto item : items)
		{
			std::cout << " | " << item ;
		}

		HelperFunctionLibrary::SkipLines(2);

		std::vector<std::string> choices{ "Quit inventory" }; 

		HelperFunctionLibrary::DisplayChoices(choices);

		HelperFunctionLibrary::SkipLine();
	}

	void Inventory::AddToInventory(std::string newItem)
	{
		if (!items.empty())
		{
			if (std::find(items.begin(), items.end(), newItem) == items.end())
			{
				items.push_back(newItem);
			}
		}
		else
		{
			items.push_back(newItem);
		}

	}

	void Inventory::Save(ST::Save& save)
	{
		save.items = items; 
	}

	void Inventory::Load(ST::Save& save)
	{
		items = save.items;
	}

	bool Inventory::Contains(std::string item)
	{
		if (std::find(items.begin(), items.end(), item) == items.end())
		{
			return false;
		}
		else
		{
			return true; 
		}
	}
}