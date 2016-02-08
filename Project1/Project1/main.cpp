#include "Core.h"
#include "test.h"
void main() {
	auto game = new Core();
	game->getLetterDisplayer()->Show("hallo");

	Base* base = Base::create("Base");
	if (base)
		base->Print();

	cin.get();
	cin.get();
	return;
}