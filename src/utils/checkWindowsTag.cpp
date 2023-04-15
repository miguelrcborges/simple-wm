#include "../globals.h"

void checkWindowsTags(Monitor &monitor) {
	for (int i = 0; i < monitor.windows.size(); ++i) {
		if (monitor.windows[i].tags & monitor.active_tag && monitor.windows[i].state != WindowState::neverMapped) {
			XMapWindow(display, monitor.windows[i].win);
		} else if (monitor.windows[i].state != WindowState::neverMapped) {
			XUnmapWindow(display, monitor.windows[i].win);
		}
	}
}
