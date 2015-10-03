#pragma once
#include <string>

namespace poker {

	struct Poker {
		int suit;
		int rank;
	};

	void initialize();
	void shuffleDeck();
	void destroy();
	std::string poker2str(Poker);
	Poker* deck;
}
