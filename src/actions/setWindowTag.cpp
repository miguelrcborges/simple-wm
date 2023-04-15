#include "../globals.h"

void setWindowTag(int tag) {
	short new_tag = 1 << tag;
	if (new_tag == monitors[active_monitor].active_tag)
		return;

	XUnmapWindow(display, last_focused);
	for (size_t i = 0; i < monitors[active_monitor].windows.size(); ++i) {
		if (monitors[active_monitor].windows[i].win == last_focused) {
			monitors[active_monitor].windows[i].tags = new_tag;
			return;
		}
	}
}
