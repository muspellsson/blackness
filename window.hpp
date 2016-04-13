#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdint>
#include <string>

class Window {
protected:
	WINDOW *win;

	Window();
public:
	Window(uint32_t, uint32_t, uint32_t, uint32_t);
	Window(Window&);
	~Window();
	Window& operator=(const Window&) = delete;

	void KeyPad(bool);
	uint32_t GetChar();
	void Refresh();
	uint32_t Width();
	uint32_t Height();
	uint32_t PosX();
	uint32_t PosY();

	template<typename... Args>
	void PrintFormat(const std::string &fmt, Args... args)
	{
		wprintw(this->win, fmt.c_str(), args...);
	}
};

#endif