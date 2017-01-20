#pragma once
#include "boost/pool/singleton_pool.hpp"

class DataBase
{
public:
	DataBase();
	~DataBase();
};

template<class TORI> class  CData : DataBase
{
private:
	TORI* pData;
	static DataManger<TORI> dm; 
public:
	CData();
	~CData();

};

