#pragma once
class GameState
{
public:

	GameState();

	virtual ~GameState();

	virtual void OnEntered() = 0;

	virtual void OnExit() = 0;

	virtual void HandleInput() = 0;
};

