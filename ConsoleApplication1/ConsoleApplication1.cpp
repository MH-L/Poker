// ConsoleApplication1.cpp : Defines the entry point for the console application.
// Author: Minghao Liu (Kevlin)
// All rights reserved.

#include "stdafx.h"
#include "ConsoleApplication1.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define POKER_SUM 54
#define RANK_SUM 13
#define SPADE 1
#define HEART 2
#define DIAMOND 3
#define CLUB 4

namespace poker {
	int _tmain(int argc, _TCHAR* argv[])
	{
		initialize();
		Poker* player1;
		Poker* player2;
		player1 = (Poker*)malloc(POKER_SUM / 2 * sizeof(Poker));
		player2 = (Poker*)malloc(POKER_SUM / 2 * sizeof(Poker));
		std::string userIn;
		std::cout << "Welcome to Poker Game." << std::endl;
		std::cout << "Would you like to play first or second?" << std::endl;
		std::cout << "Enter yes for first or no for second." << std::endl;
		std::cin >> userIn;
		if (userIn.compare("yes") || userIn.compare("no")) {
			printf("You have succeeded.");
		}
		int counter = 0;
		while (counter < POKER_SUM) {
			int index = counter / 2;
			printf("Now you get a new card, which is %s\n", poker2str(*(deck + counter)).c_str());
			if (counter % 2 == 0)
				*(player1 + index) = *(deck + counter);
			else
				*(player2 + index) = *(deck + counter);
			counter++;

		}
		free(player1);
		free(player2);
		destroy();
		getchar();
		return 0;
	}

	Poker* deck;

	void initialize() {
		deck = (Poker*)malloc(POKER_SUM * sizeof(Poker));
		*deck = Poker{ 0, 0 };
		*(deck + 1) = Poker{ 0, 1 };
		for (int i = 2; i < POKER_SUM; i++) {
			int suitNum = 1 + (i - 1) / RANK_SUM;
			int rankNum = (i - 1) % RANK_SUM;
			*(deck + i) = Poker{ suitNum, rankNum };
		}
	}

	void shuffleDeck() {
		// do nothing now.
		std::vector<int> appeared = {};
		Poker* newDeck = (Poker*)malloc(POKER_SUM * sizeof(Poker));
		int counter = 0;
		while (counter < POKER_SUM) {
			int randN = rand() % POKER_SUM;
			while (std::find(appeared.begin(), appeared.end(), randN) != appeared.end()) {
				randN = rand() % POKER_SUM;
			}
			*(newDeck + counter) = *(deck + randN);
			counter++;
		}
	}

	void destroy() {
		free(deck);
	}

	std::string poker2str(Poker p) {
		std::string returnVal = "";
		switch (p.suit) {
		case 0:
			if (p.rank == 0)
				returnVal = "Big Joker";
			else if (p.rank == 1)
				returnVal = "Small Joker";
			return returnVal;
		case 1:
			returnVal = "Spade ";
			break;
		case 2:
			returnVal = "Heart ";
			break;
		case 3:
			returnVal = "Diamond ";
			break;
		case 4:
			returnVal = "Club ";
			break;
		default:
			// throw "Invalid Poker Card!";
			return "Error!";
		}

		returnVal += p.rank;
		return returnVal;
	}

} // namespace poker
