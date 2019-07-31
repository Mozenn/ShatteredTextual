#pragma once
#include "GameState.h"
#include <string>

class InventoryMenu :public GameState
{
public:

	InventoryMenu();

	~InventoryMenu();

	virtual void OnEntered() override;

	virtual void OnExit() override;

	virtual void HandleInput()override;
};

