#pragma once
#include <concurrent_vector.h>
#include "CData.h"
#include "DataManager.h"
using namespace concurrency;
class Manager : concurrency::concurrent_vector<DataManagerBase>
{
private:
public:

	Manager()
	{
	}

	~Manager()
	{
	}
	template <T> void add<T>(T comp) 
	{
		Manager<T>
	}

};

