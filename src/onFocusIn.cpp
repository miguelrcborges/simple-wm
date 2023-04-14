#include <X11/Xlib.h>

#include <iostream>

extern Window last_focused;

void onFocusIn(const XFocusChangeEvent &event) {
	last_focused = event.window;
	std::cout << "The last focused window is " << event.window << '\n';
}
