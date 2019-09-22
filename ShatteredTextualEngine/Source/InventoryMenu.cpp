#include "InventoryMenu.h"
#include <vector>
#include "HelperFunctionLibrary.h"
#include "GameInstance.h"

namespace ST
{


	InventoryMenu::InventoryMenu(std::string p_name) : GameState(p_name)
	{

	}

	void InventoryMenu::HandleInput(int input)
	{
		if (input == 1)
		{
			OnStateEnd.Broadcast<std::string>("");
		}

	}

	void InventoryMenu::Display()
	{
		GameInstance::Get().DisplayInventory();
	}
}