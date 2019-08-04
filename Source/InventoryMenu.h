#pragma once
#include "GameState.h"
#include <string>

namespace SL
{
	class InventoryMenu :public GameState
	{
	public:

		InventoryMenu();

		~InventoryMenu();

		virtual void Display() override;

		virtual void HandleInput() override;
	};
}



