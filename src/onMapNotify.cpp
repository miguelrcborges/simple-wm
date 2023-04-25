#include "globals.h"
#include "utils/utils.h"

#include <X11/Xutil.h>

void onMapNotify(const XMapEvent &event) {
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {
			if (event.window == monitors[i].windows[ii].win) {
				switch (monitors[i].windows[ii].state) {
				case WindowState::neverMapped:
					monitors[i].windows[ii].tags = monitors[i].active_tag;
					monitors[i].windows[ii].state = WindowState::tiled;
					++monitors[i].stack_count;
					rearrangeMonitor(monitors[i]);
					break;

				case WindowState::hidden_tiled:
					monitors[i].windows[ii].state = WindowState::tiled;
					++monitors[i].stack_count;
					rearrangeMonitor(monitors[i]);
					break;

				case WindowState::hidden_floating:
					monitors[i].windows[ii].state = WindowState::floating;
					break;

				case WindowState::hidden_fullscreen:
					monitors[i].windows[ii].state = WindowState::fullscreen;
					break;

				default:
					break;
				}

				return;
			}
		}
	}
}
