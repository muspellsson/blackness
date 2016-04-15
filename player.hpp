#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdint>

typedef enum race {
	RaceHuman=0,
	RaceElf,
	RaceTroll,
	RaceDwarf,
	RaceMinotaur,
	RaceVampire
} race_t;

class Player {
	int32_t x, y;
	int32_t hp, sp;
	race_t race;

	Player();
	void PutAt(int32_t, int32_t);

};

#endif