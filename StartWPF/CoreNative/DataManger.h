#pragma once
#include "boost/pool/singleton_pool.hpp"
struct MyPoolTag {};
class DataMangerBase
{
public:
	DataMangerBase();
	~DataMangerBase();
};
template <class TORI> class DataManger:DataMangerBase
{
private:
	
	typedef boost::singleton_pool<MyPoolTag, sizeof(TORI)> SP;
	SP sp;
public:
	DataManger();
	~DataManger();

};

