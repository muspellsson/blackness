#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdint>

class Player {
	uint32_t x, y;
	uint32_t hp, sp;

	Player();
	void PutAt(uint32_t, uint32_t);

};

#endif