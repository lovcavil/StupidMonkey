#include "Core.h"



Core::Core()
{
	mpLetterDisplayer = new LetterDisplayer();
}


Core::~Core()
{
}

LetterDisplayer* Core::getLetterDisplayer()
{
	return mpLetterDisplayer;
}