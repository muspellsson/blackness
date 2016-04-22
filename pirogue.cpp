#include <cstdint>
#include <list>
#include <array>

#define MAP_WIDTH  32
#define MAP_HEIGHT 32

typedef enum {
	Black=0,
	White=1
} color_t;

class Creature {
public:
	int32_t hp = 1;
	/* Damage */
	/* dices D sides + bsdmg */
	int32_t bsdmg = 0;
	int32_t dices = 1;
	int32_t sides = 1;
	/* Coordinates on map */
	int16_t x = 0;
	int16_t y = 0;

	Creature() {};
};

class Player : Creature {

};

class Object {

};

class Tile {
public:
	bool passable = true;
	char glyph = '#';
	std::list<Object*> *objects = new std::list<Object*>;

	~Tile() { delete objects; }
};

class Map {
public:
	std::array<Tile*, MAP_WIDTH> *tiles;

	Map() :
		tiles(new std::array<Tile*, MAP_WIDTH>())
	{
		for (int i = 0; i < MAP_WIDTH; i++) {
			for (int j = 0; j < MAP_HEIGHT; j++) {
				tiles[0][j] = new Tile();
			}
		}
	}
};



int main()
{

}