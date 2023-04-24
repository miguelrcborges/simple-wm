#include "globals.h"

#include <iostream>

void onMotionNotify(const XMotionEvent &event) {
#ifdef XINERAMA
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		if (event.x >= monitors[i].x && event.x <= monitors[i].x + monitors[i].width && event.y >= monitors[i].y &&
		    event.y <= monitors[i].y + monitors[i].height) {
			active_monitor = i;
			break;
		}
	}
#endif

	if (cursor_action == cursorAction::Moving) {
		XMoveResizeWindow(display, last_focused->win, event.x, event.y, last_focused->width, last_focused->height);
	} else if (cursor_action == cursorAction::Resizing) {
		XMoveResizeWindow(display, last_focused->win, last_focused->x, last_focused->y, event.x - last_focused->x, event.y - last_focused->y);
	}
}
