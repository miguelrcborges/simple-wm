#include "../globals.h"
#include "../utils/utils.h"

#include <climits>

void rotateStack(int positions) {
	if (monitors[active_monitor].stack_count <= 1) return;
	while (positions) {
		if (positions > 0) {
			Client tmp;
			size_t first = SSIZE_MAX;
			for (size_t i = 0; i < monitors[active_monitor].windows.size(); ++i) {
				if (monitors[active_monitor].windows[i].state == WindowState::tiled) {
					if (first == SSIZE_MAX) {
						first = i;
						tmp = monitors[active_monitor].windows[i];
					} else {
						Client tmp2 = monitors[active_monitor].windows[i];
						monitors[active_monitor].windows[i] = tmp;
						tmp = tmp2;
					}
				}
			}

			monitors[active_monitor].windows[first] = tmp;
			--positions;

		} else {
			Client tmp;
			size_t first = SSIZE_MAX;
			
			size_t i = monitors[active_monitor].windows.size();
			while (i --> 0) {
				if (monitors[active_monitor].windows[i].state == WindowState::tiled) {
					if (first == SSIZE_MAX) {
						first = i;
						tmp = monitors[active_monitor].windows[i];
					} else {
						Client tmp2 = monitors[active_monitor].windows[i];
						monitors[active_monitor].windows[i] = tmp;
						tmp = tmp2;
					}
				}
			}
			
			monitors[active_monitor].windows[first] = tmp;
			++positions;

		}
	}
	rearrangeMonitor(monitors[active_monitor]);
}
