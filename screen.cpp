#include <curses.h>
#include "screen.hpp"

Screen::Screen()
{
	this->stdscr = initscr();
}

Screen::~Screen()
{
	endwin();
}