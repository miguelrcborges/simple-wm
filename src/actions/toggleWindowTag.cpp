#include "../globals.h"

void toggleWindowTag(int tag) {
	for (int i = 0; i < monitors[active_monitor].windows.size(); ++i) {
		if (monitors[active_monitor].windows[i].win == last_focused) {
			int new_tag = monitors[active_monitor].windows[i].tags ^ (1 << tag);
			if (new_tag)
				monitors[active_monitor].windows[i].tags = new_tag;
			else
				return;

			if (!(new_tag ^ monitors[active_monitor].active_tag)) {
				XUnmapWindow(display, monitors[active_monitor].windows[i].tags);
			}
		}
	}
}
