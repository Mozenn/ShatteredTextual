#pragma once
#include <functional>
#include <vector>

namespace SL
{

	template<class F>
	class Event
	{

	public:

		void Add(std::function<F> newFunction)
		{
			//if (!Contains(newFunction))
			//{
			//	functions.push_back(newFunction);
			//}

			functions.push_back(newFunction);
		}

		//bool Contains(std::function<F> function)
		//{
		//	for (auto func : functions)
		//	{
		//		if (func == function)
		//			return true; 
		//	}

		//	return false; 
		//}

		void Clear()
		{
			if (!functions.empty())
			{
				functions.clear();
			}
		}

		template <class T>
		void Broadcast(T arg)
		{
			for (auto func : functions)
			{
				func(arg);
			}
		}

		void Broadcast()
		{
			for (auto func : functions)
			{
				func();
			}
		}

		template <class T, class S>
		void Broadcast(T arg, S arg2)
		{
			for (auto func : functions)
			{
				func(arg, arg2);
			}
		}

	private:

		// vector of std::func 
		std::vector<std::function<F>> functions;
	};

}