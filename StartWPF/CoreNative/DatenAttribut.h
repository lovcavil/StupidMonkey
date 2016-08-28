#pragma once

#include "stdafx.h"

using namespace std;

#ifndef LX_DLL_CLASS_EXPORTS
#define LX_DLL_CLASS __declspec(dllexport)
#else
#define LX_DLL_CLASS __declspec(dllimport)
#endif

class LX_DLL_CLASS DatenAttribut
{
public:

	DatenAttribut()
	{
	}

	~DatenAttribut()
	{
	}
};

