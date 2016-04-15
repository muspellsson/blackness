#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdint>
#include <string>

class Window {
protected:
	WINDOW *win;

	Window();
public:
	Window(int32_t, int32_t, int32_t, int32_t);
	Window(Window&);
	~Window();
	Window& operator=(const Window&) = delete;

	void KeyPad(bool);
	int32_t GetChar();
	void Refresh();
	int32_t Width();
	int32_t Height();
	int32_t PosX();
	int32_t PosY();

	template<typename... Args>
	void PrintFormat(const std::string &fmt, Args... args)
	{
		wprintw(this->win, fmt.c_str(), args...);
	}
};

#endif