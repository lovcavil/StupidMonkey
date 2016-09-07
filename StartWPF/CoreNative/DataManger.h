#pragma once
class DataMangerBase
{
public:
	DataMangerBase();
	~DataMangerBase();
};
template <class TORI> class DataManger:DataMangerBase
{
private:
	DataManger* psdm;
public:
	DataManger();
	~DataManger();

};

