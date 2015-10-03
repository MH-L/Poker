// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	std::string userIn;
	std::cout << "Welcome to Poker Game." << std::endl;
	std::cout << "Would you like to play first or second?" << std::endl;
	std::cout << "Enter yes for first or no for second." << std::endl;
	std::cin >> userIn;
	if (userIn.compare("yes") || userIn.compare("no")) {
		printf("You have succeeded.");
	}
	getchar();
	return 0;
}

