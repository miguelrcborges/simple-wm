#include "globals.h"

#include <X11/Xatom.h>

void onEnterNotify(const XCrossingEvent &event) {
	for (size_t i = 0; i < monitors[active_monitor].windows.size(); ++i) {
		if (monitors[active_monitor].windows[i].win == event.window) {
			last_focused = &(monitors[active_monitor].windows[i]);
			return;
		}
	}
}
