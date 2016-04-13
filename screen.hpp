#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <cstdint>
#include <curses.h>
#include "window.hpp"

class Screen : public Window {

public:
	Screen();
	~Screen();

	void CursorOn();
	void CursorOff();
	void Raw();
	void NoRaw();
	void CBreak();
	void NOCBreak();
	void Echo();
	void NoEcho();
};

#endif