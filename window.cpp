#include <cstdint>
#include <iostream>
#include <curses.h>
#include "window.hpp"

using namespace std;

Window::Window() :
	win(0)
{

}

Window::Window(int32_t w, int32_t h, int32_t x, int32_t y) :
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
	int32_t x = wwin.PosX();
	int32_t y = wwin.PosY();
	int32_t w = wwin.Width();
	int32_t h = wwin.Height();
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

int32_t Window::GetChar()
{
	return wgetch(this->win);
}

void Window::Refresh()
{
	if (wrefresh(this->win) != OK) {
		cerr << "Error while refreshing window: " << this << endl;
	}
}

int32_t Window::Width()
{
	return getmaxx(this->win);
}

int32_t Window::Height()
{
	return getmaxy(this->win);
}

int32_t Window::PosX()
{
	return getbegx(this->win);
}

int32_t Window::PosY()
{
	return getbegy(this->win);
}