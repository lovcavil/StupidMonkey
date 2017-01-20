#pragma once

#include <concurrent_vector.h>
#include "Manager.h"

using namespace concurrency;
using namespace std;
class DataManagerBase
{
private:
	
public:
	Manager manager;
	DataManagerBase()
	{
	}

	~DataManagerBase()
	{
	}
};

template <T> class DataManager<T> : DataManagerBase
{
private:
	concurrent_vector<T> vData;
public:
	DataManager()
	{
	}

	~DataManager()
	{
	}

	void addData(a) {
		vData.push_back(a)£»
	}
};