#include "../globals.h"

void killWindow() {
	if (last_focused != nullptr) {
		XKillClient(display, last_focused->win);
		last_focused = nullptr;
	}
	XFlush(display);
}
