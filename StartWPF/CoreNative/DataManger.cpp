#include "stdafx.h"
#include "DataManger.h"


template <class  TORI>  DataManger<TORI>::DataManger()
{
	if (psdm==NULL)
	{
		psdm=new DataManger
	}
}


template <class  TORI>  DataManger<TORI>::~DataManger()
{
}

DataMangerBase::DataMangerBase()
{

}

DataMangerBase::~DataMangerBase()
{

}
