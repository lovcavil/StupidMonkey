#pragma once
#include "DataManager.h"
class CDataBase abstract
{
	void add() {
		;
	}
	virtual void addData() {
		;
	}

};

template<class T> class CData : CDataBase
{
private:
	static DataManager<T> dataManager;

public:

	CData()
	{
		if (dataManager ==nullptr)
		{
			dataManager = new DataManager<T>();
		}
	}

	~CData()
	{
	}

	void addData(T a) override
	{
		dataManager.addData(a);
	}
};

class intData : CData<int>
{

};