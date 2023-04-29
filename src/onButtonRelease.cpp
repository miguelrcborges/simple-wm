#include "globals.h"

void onButtonRelease(const XButtonEvent &event) {
	cursor_action = cursorAction::NoAction;
	XUngrabPointer(display, CurrentTime);

#ifdef XINERAMA
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (auto ii = monitors[i].windows.begin(); ii != monitors[i].windows.end(); ++ii) {
			if (last_focused && ii->win == last_focused->win) {
				if (i != active_monitor) {
					ii->tags = monitors[active_monitor].active_tag;
					monitors[active_monitor].windows.emplace_back(*ii);
					monitors[i].windows.erase(ii);
				}
				return;
			}
		}
	}
#endif
}
