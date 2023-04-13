#include <X11/Xlib.h>

#include "config.h"
#include "Monitor.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

#ifdef XINERAMA
extern int amount_of_connected_monitors;
#endif

void onConfigureNotify(const XConfigureEvent &event) {
#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i) {
		for (int ii = 0; ii < monitors[i].windows.size(); ++ii) {
#else
		for (int ii = 0; ii < monitors[0].windows.size(); ++ii) {
#endif
			if (event.window == monitors[i].windows[i].win) {
				monitors[i].windows[i].x = event.x;
				monitors[i].windows[i].y = event.y;
				monitors[i].windows[i].width = event.width;
				monitors[i].windows[i].height = event.height;
				return;
			}
		}
#ifdef XINERAMA
	}
#endif
}
