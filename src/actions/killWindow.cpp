#include <X11/Xlib.h>

#include <iostream>

extern Display *display;
extern Window root_window;
extern Window last_focused;

void killWindow() {
	if (last_focused != root_window) {
		XKillClient(display, last_focused);
		std::cout << "Deleting window " << last_focused << '\n'; 
		last_focused = root_window;
	} 
	XFlush(display);
}
