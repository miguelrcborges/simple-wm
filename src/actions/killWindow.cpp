#include <X11/Xlib.h>

extern Display *display;
extern Window root_window;
extern Window last_focused;

void killWindow() {
	if (last_focused != root_window) {
		XKillClient(display, last_focused);
		last_focused = root_window;
	} 
	XFlush(display);
}
