#include "globals.h"

#include <X11/Xutil.h>

#include "utils/utils.h"

extern Monitor monitors[max_number_of_monitors];

#ifdef XINERAMA
extern int amount_of_connected_monitors;
#endif

void onMapNotify(const XMapEvent &event) {

#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i)
		for (int ii = 0; ii < monitors[i].windows.size(); ++ii)
			if (event.window == monitors[i].windows[ii].win) {
				monitors[i].windows[ii].state = WindowState::tiled;
				rearrangeMonitor(monitors[i]);
				return;
			}

#else
	rearrangeMonitor(monitors[0]);
#endif
}
