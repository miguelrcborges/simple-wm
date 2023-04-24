#include "globals.h"

#include <X11/Xutil.h>

#include "utils/utils.h"

void onUnmapNotify(const XUnmapEvent &event) {

#ifdef XINERAMA
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
#else
	constexpr size_t i = 0;
#endif
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {
			if (event.window == monitors[i].windows[ii].win) {
				if (monitors[i].windows[ii].state == WindowState::tiled)
					--monitors[i].stack_count;
				monitors[i].windows[ii].state = WindowState::hidden;
				rearrangeMonitor(monitors[i]);
				return;
			}
		}
#ifdef XINERAMA
	}
#endif
}
