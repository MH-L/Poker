#pragma once
#include <string>

namespace poker {

	struct Poker {
		int suit;
		int rank;
	};

	extern Poker* deck;
	void initialize();
	void shuffleDeck();
	void destroy();
	std::string poker2str(Poker);
}
