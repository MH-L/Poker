// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define POKER_SUM 54
#define RANK_SUM 13

struct Poker {
	int club;
	int rank;
};

Poker* deck;

int _tmain(int argc, _TCHAR* argv[])
{
	initialize();
	std::string userIn;
	std::cout << "Welcome to Poker Game." << std::endl;
	std::cout << "Would you like to play first or second?" << std::endl;
	std::cout << "Enter yes for first or no for second." << std::endl;
	std::cin >> userIn;
	if (userIn.compare("yes") || userIn.compare("no")) {
		printf("You have succeeded.");
	}
	while (true) {
		std::cout << "Now you get a new card, which is " << std::endl;
		if (noCardLeft())
			break;
	}
	getchar();
	return 0;
}

void initialize() {
	deck = (Poker*)malloc(POKER_SUM * sizeof(Poker));
	*deck = Poker{ 0, 0 };
	*(deck + 1) = Poker{ 0, 1 };
	for (int i = 2; i < POKER_SUM; i++) {
		int clubNum = 1 + (i - 1) / RANK_SUM;
		int rankNum = (i - 1) % RANK_SUM;
		*(deck + i) = Poker{ clubNum, rankNum };
	}
}

bool noCardLeft() {

}

void shuffleDeck() {

}
