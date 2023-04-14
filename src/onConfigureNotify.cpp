#include "globals.h"

void onConfigureNotify(const XConfigureEvent &event) {
#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i) {
		for (int ii = 0; ii < monitors[i].windows.size(); ++ii) {
#else
	int i = 0;
	for (int ii = 0; ii < monitors[0].windows.size(); ++ii) {
#endif
			if (event.window == monitors[i].windows[i].win) {
				monitors[i].windows[ii].x = event.x;
				monitors[i].windows[ii].y = event.y;
				monitors[i].windows[ii].width = event.width;
				monitors[i].windows[ii].height = event.height;
				return;
			}
		}
#ifdef XINERAMA
	}
#endif
}
