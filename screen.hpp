#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <curses.h>

class Screen {
	WINDOW *stdscr;

public:
	Screen();
	~Screen();
};

#endif