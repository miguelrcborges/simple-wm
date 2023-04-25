#include "globals.h"

void onConfigureNotify(const XConfigureEvent &event) {
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {
			if (event.window == monitors[i].windows[ii].win) {
				monitors[i].windows[ii].x = event.x;
				monitors[i].windows[ii].y = event.y;
				monitors[i].windows[ii].width = event.width;
				monitors[i].windows[ii].height = event.height;
				return;
			}
		}
	}
}
