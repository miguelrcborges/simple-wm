#include <iostream>

#include <X11/Xlib.h>
#include <X11/keysymdef.h>

void onKeyPress(const XKeyEvent &event) {
	std::cout << "You pressed the key: " << event.keycode << '\n';
}
