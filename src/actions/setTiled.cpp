#include "../globals.h"
#include "../utils/utils.h"

void setTiled(void) {
	if (last_focused == nullptr) return;
	if (last_focused->state == WindowState::tiled) return;

	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {
			if (monitors[i].windows[ii].win == last_focused->win) {
				monitors[i].windows[ii].state = WindowState::tiled;
				++monitors[i].stack_count;
				rearrangeMonitor(monitors[i]);
			}
		}
	}
}
