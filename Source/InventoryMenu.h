#pragma once
#include "GameState.h"
#include <string>

namespace SL
{
	class InventoryMenu :public GameState
	{
	public:

		InventoryMenu();

		InventoryMenu(std::string p_name);

		virtual void Display() override;

		virtual void HandleInput(int input) override;
	};
}


