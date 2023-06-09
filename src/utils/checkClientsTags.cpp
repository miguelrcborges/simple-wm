#include "../globals.h"

void checkClientTags(Monitor &monitor) {
	for (size_t i = 0; i < monitor.windows.size(); ++i) {
		if (monitor.windows[i].tags & monitor.active_tag && monitor.windows[i].state != WindowState::neverMapped) {
			XMapWindow(display, monitor.windows[i].win);
		} else if (monitor.windows[i].state != WindowState::neverMapped) {
			XUnmapWindow(display, monitor.windows[i].win);
		}
	}
}
