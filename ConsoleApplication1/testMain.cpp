#include "stdafx.h"
#include "ConsoleApplication1.h"
#include <cassert>
#include <string>

int main() {
	poker::Poker p = poker::Poker{ 0,0 };
	std::string result = poker::poker2str(p);
	assert(result == "Big Joker");
	poker::Poker p1 = poker::Poker{ 1,1 };
	result = poker::poker2str(p1);
	assert(result == "Spade 1.");
	return 0;
}