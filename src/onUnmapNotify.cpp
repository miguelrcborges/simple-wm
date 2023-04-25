#include "globals.h"

#include <X11/Xutil.h>

#include "utils/utils.h"

void onUnmapNotify(const XUnmapEvent &event) {
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {
			if (event.window == monitors[i].windows[ii].win) {
				switch (monitors[i].windows[ii].state) {
				case WindowState::tiled:
					--monitors[i].stack_count;
					monitors[i].windows[ii].state = WindowState::hidden_tiled;
					rearrangeMonitor(monitors[i]);
					break;

				case WindowState::fullscreen:
					monitors[i].windows[ii].state = WindowState::hidden_fullscreen;
					break;

				case WindowState::floating:
					monitors[i].windows[ii].state = WindowState::hidden_floating;
					break;

				default:
					break;
				}

				return;
			}
		}
	}
}
