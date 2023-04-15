#include "globals.h"

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
}
