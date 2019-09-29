#pragma once

#include "GameState.h"
#include "Level.h"
#include <stack>
#include <memory>
#include <string>
#include <functional>
#include "GameInstance.h"

namespace ST
{
	using StateRef = std::shared_ptr<GameState>;

	//class GameInstance; 

	class GameStateManager
	{
	public:

		/* Assign owning instance member ptr */
		GameStateManager(GameInstance* p_owingInstance);

		/*
		Initialize first state 
		*/
		template<class T>
		void Initialize(std::string startState = "Start") // Here to modify default start level on new game 
		{
			StateRef newState = std::make_shared<T>(startState);

			states.push(newState);

			//bind endstate event 
			std::function<void(std::string)> function = std::bind(&GameStateManager::HandleCurrentStateEnd,this,std::placeholders::_1);
			newState->OnStateEnd.Add(function);

			auto newLevel = std::dynamic_pointer_cast<Level>(newState);
			if (newLevel)
			{
				// bind onNewItem event 
				std::function<void(std::string)> itemFunction = std::bind(&GameInstance::HandleOnNewItem, owingInstance, std::placeholders::_1);
				newLevel->OnNewItem.Add(itemFunction);

				// bind onNewprogevent event
				std::function<void(std::string)> progFunction = std::bind(&GameInstance::HandleOnNewProgressionEvent, owingInstance, std::placeholders::_1);
				newLevel->OnNewProgressionEvent.Add(progFunction);
			}

			
		}

		void DisplayCurrentState();

		/*
		Add new state into the stack 
		Optionaly remove current top state of the stack 
		*/
		template<class T>
		void LoadNewState(std::string stateName, bool isReplacing)
		{
			if (states.top()->GetName() != stateName)
			{

				// Remove current state of stack 
				if (isReplacing && !states.empty())
				{
					StateRef oldState;
					oldState = states.top();
					oldState->OnStateEnd.Clear();
					states.pop();

				}

				// Add new state in stack 

				StateRef newState = std::make_shared<T>(stateName);

				states.push(newState);

				std::function<void(std::string)> function = std::bind(&GameStateManager::HandleCurrentStateEnd, this, std::placeholders::_1);
				newState->OnStateEnd.Add(function);

				auto newLevel = std::dynamic_pointer_cast<Level>(newState);
				if (newLevel)
				{
					// bind onNewItem event 
					std::function<void(std::string)> itemFunction = std::bind(&GameInstance::HandleOnNewItem, owingInstance, std::placeholders::_1);
					newLevel->OnNewItem.Add(itemFunction);

					// bind onNewprogevent event
					std::function<void(std::string)> progFunction = std::bind(&GameInstance::HandleOnNewProgressionEvent, owingInstance, std::placeholders::_1);
					newLevel->OnNewProgressionEvent.Add(progFunction);
				}
			}

		}

		void HandleInput(int input);

		/* handler called on state removed */
		void HandleCurrentStateEnd(std::string nextState = "");

		std::string GetCurrentStateName(); 

	protected:

		/*
		Stack of State 
		FIFO 
		*/
		std::stack<StateRef> states;

		GameInstance* owingInstance; 
	};
}



