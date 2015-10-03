#include "stdafx.h"
#include "ConsoleApplication1.cpp"
#include <cassert>
#include <string>

int main() {
	Poker p = Poker{ 0,0 };
	std::string result = poker2str(p);
	assert(result == "Big Joker");
	return 0;
}