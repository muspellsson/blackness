#include <cstdint>
#include <iostream>
#include <curses.h>
#include "window.hpp"

using namespace std;

Window::Window() :
	win(0)
{

}

Window::Window(uint32_t w, uint32_t h, uint32_t x, uint32_t y) :
	win(newwin(h, w, x, y))
{
	if (this->win == 0) {
		cerr << "Error while creating window instance: " << this 
			<< endl;
	}
}

Window::Window(Window &wwin) :
	win(0)
{
	uint32_t x = wwin.PosX();
	uint32_t y = wwin.PosY();
	uint32_t w = wwin.Width();
	uint32_t h = wwin.Height();
	this->win = newwin(h, w, x, y);
	if (this->win == 0) {
		cerr << "Error while creating window instance: " << this 
			<< endl;
	}
}

Window::~Window()
{
	if (delwin(this->win) != OK) {
		cerr << "Error while deleting window instance: " << this 
			<< endl;
	}
}

void Window::KeyPad(bool bf)
{
	if (keypad(this->win, bf) != OK) {
		cerr << "Error while calling keypad on window: " << this
			<< endl;
	}
}

uint32_t Window::GetChar()
{
	return uint32_t(wgetch(this->win));
}

void Window::Refresh()
{
	if (wrefresh(this->win) != OK) {
		cerr << "Error while refreshing window: " << this << endl;
	}
}

uint32_t Window::Width()
{
	return getmaxx(this->win);
}

uint32_t Window::Height()
{
	return getmaxy(this->win);
}

uint32_t Window::PosX()
{
	return getbegx(this->win);
}

uint32_t Window::PosY()
{
	return getbegy(this->win);
}