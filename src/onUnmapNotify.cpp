#include "globals.h"

#include <X11/Xutil.h>

#include "utils/utils.h"


void onUnmapNotify(const XUnmapEvent &event) {

#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i)
		for (int ii = 0; ii < monitors[i].windows.size(); ++ii)
			if (event.window == monitors[i].windows[ii].win) {
				monitors[i].windows[ii].state = WindowState::hidden;
				--monitors[i].stack_count;
				rearrangeMonitor(monitors[i]);
				return;
			}

#else
	rearrangeMonitor(monitors[0]);
#endif
}
