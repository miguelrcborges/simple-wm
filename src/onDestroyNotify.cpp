#include "globals.h"
#include "utils/utils.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];
extern Window root_window;
extern Window last_focused;

#ifdef XINERAMA
extern int amount_of_connected_monitors;
#endif

void onDestroyNotify(const XDestroyWindowEvent &event) {
#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i) {
		for (auto ii = monitors[0].windows.begin(); ii != monitors[0].windows.end(); ++ii) {
			if (ii->win == event.window) {
				monitors[i].windows.erase(ii);
				rearrangeMonitor(monitors[i]);
				return;
			}
		}
	}
#else
	for (auto i = monitors[0].windows.begin(); i != monitors[0].windows.end(); ++i) {
		if (i->win == event.window) {
			monitors[0].windows.erase(i);
			rearrangeMonitor(monitors[0]);
			return;
		}
	}
#endif
}
