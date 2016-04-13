#include <memory>
#include "screen.hpp"
#include "window.hpp"

int main()
{
	std::unique_ptr<Screen> scr(new Screen());
	scr->CursorOff();
	scr->Raw();
	scr->KeyPad(true);
	scr->NoEcho();
	scr->PrintFormat("Hello from curses: %d", 10);
	scr->Refresh();
	scr->GetChar();
	return 0;
}