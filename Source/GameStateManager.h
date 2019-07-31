#pragma once

#include "GameState.h"
#include <stack>
#include <memory>

using StateRef = std::unique_ptr<GameState>;

class GameStateManager
{
public:

	GameStateManager();

	~GameStateManager();

	void PushState(StateRef State, bool isReplacing);

	void PopState();


	void HandleInput();

	void Update();

	void Draw();

	StateRef getCurrentState() const;

protected:

	std::stack<StateRef> states;
};

