#pragma once
#include "LetterDisplayer.h"
class Core
{
private:
	LetterDisplayer* mpLetterDisplayer;
public:
	Core();
	~Core();
	LetterDisplayer* getLetterDisplayer();
};

