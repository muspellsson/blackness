#include <cstdint>
#include <curses.h>
#include "screen.hpp"

Screen::Screen()
{
	this->win = initscr();
}

Screen::~Screen()
{
	endwin();
}

void Screen::CursorOn()
{
	curs_set(1);
}

void Screen::CursorOff()
{
	curs_set(0);
}

void Screen::Raw()
{
	raw();
}

void Screen::NoRaw()
{
	noraw();
}

void Screen::Echo()
{
	echo();
}

void Screen::CBreak()
{
	cbreak();
}

void Screen::NOCBreak()
{
	nocbreak();
}

void Screen::NoEcho()
{
	noecho();
}