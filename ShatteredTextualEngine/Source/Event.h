#pragma once
#include <functional>
#include <vector>

namespace ST
{

	template<class F>
	class Event
	{

	public:

		/* Add a new function to this event instance */
		void Add(std::function<F> newFunction)
		{
			functions.push_back(newFunction);
		}

		/* Clear all functions bound to this instance */
		void Clear()
		{
			if (!functions.empty())
			{
				functions.clear();
			}
		}

		/* call all functions bound to this instance 
		 one parameter */
		template <class T>
		void Broadcast(T arg)
		{
			for (auto func : functions)
			{
				func(arg);
			}
		}

		/* call all functions bound to this instance
		no parameter */
		void Broadcast()
		{
			for (auto func : functions)
			{
				func();
			}
		}

		/* call all functions bound to this instance
		two parameter */
		template <class T, class S>
		void Broadcast(T arg, S arg2)
		{
			for (auto func : functions)
			{
				func(arg, arg2);
			}
		}

	private:

		/* vector of bound functions */
		std::vector<std::function<F>> functions;
	};

}