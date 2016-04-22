import std.stdio;
import std.container;
import video;

enum Color {
	Black=0,
	White
}

class Creature {
	// Hit Points
	int hp = 1;
	// Damage
	// dices D sides + bsdmg
	int bsdmg = 0;
	int dices = 1;
	int sides = 1;
	// Coordinats on map
	int x = 0;
	int y = 0;
}

class Player : Creature {

}

class Item {

}

class Tile {
	bool passable = true;
	char glyph = '#';
	SList!Item items = SList!Item();
}

class Map {
	int width;
	int height;
	Tile[][] tiles;

	this(int w = 32, int h = 32) {
		this.width  = w;
		this.height = h;
		tiles = new Tile[][](w, h);
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				tiles[i][j] = new Tile();
			}
		}
	}

	void draw(Window w, int x, int y) {
		for (int j = 0; j < w.height; j++) {
			for (int i = 0; i < w.width; i++) {
				if (((x + i) < this.width) && ((y + j) < this.height)) {
					w.addChar(i, j, tiles[x+i][y+j].glyph);
				}
			}
		}
	}

	void DebugP(Window s) {
		for (int i = 0; i < this.height; i++) {
			for (int j = 0; j < this.width; j++) {
				s.addChar(tiles[j][i].glyph);
			}
			s.addChar('\n');
		}	
	}
}


int main()
{
	auto s = new Screen();
	auto w = new Window(4, 4, 0, 0);
	auto a = new Map(10, 10);
	a.draw(w, 2, 2);
	//a.DebugP(w);
	w.refresh();
	//w.dod();
	w.refresh();
	w.getChar();
	return 0;
}