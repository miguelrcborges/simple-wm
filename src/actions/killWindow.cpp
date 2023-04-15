#include "../globals.h"

void killWindow() {
	if (last_focused != root_window) {
		XKillClient(display, last_focused);
		last_focused = root_window;
	}
	XFlush(display);
}
