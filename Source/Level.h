#pragma once

#include <string>
#include "GameState.h"

class Level : public GameState
{
public:

	Level();

	Level(std::string levelName);

	~Level();

	virtual void OnEntered() override ;

	virtual void OnExit() override;

	virtual void HandleInput()override;
};

