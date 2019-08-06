#include "Inventory.h"
#include "Save.h"
#include "HelperFunctionLibrary.h"
#include <iostream>
#include <algorithm>

namespace SL
{
	void Inventory::DisplayInventory()
	{
		HelperFunctionLibrary::SkipLine();
		HelperFunctionLibrary::DisplayLine();
		HelperFunctionLibrary::SkipLine();

		for (auto item : items)
		{
			std::cout << item << " | "; 
		}

		HelperFunctionLibrary::SkipLine();

		std::vector<std::string> choices{ "quit inventory" }; 

		HelperFunctionLibrary::DisplayChoices(choices);
	}

	void Inventory::AddToInventory(std::string newItem)
	{
		if (std::find(items.begin(),items.end(),newItem) != items.end())
		{
			items.push_back(newItem);
		}
	}

	void Inventory::Save(SL::Save& save)
	{
		save.items = items; 
	}

	void Inventory::Load(SL::Save& save)
	{
		items = save.items;
	}
}