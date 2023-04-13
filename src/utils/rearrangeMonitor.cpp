#include <X11/Xlib.h>

#include "../config.h"
#include "../Monitor.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

void rearrangeMonitor(Monitor &monitor) {
	int width_without_padding = monitor.width - (2 * gap_size);
	if (monitor.num_of_masters != 0 && monitor.num_of_masters != monitor.windows.size() && monitor.windows.size() == 1)
		width_without_padding -= gap_size;

	int master_window_width = 0;
	if (monitor.num_of_masters >= 1) {
		int master_window_height = (monitor.height - (1 + monitor.num_of_masters) * gap_size) / monitor.num_of_masters;
		if (monitor.windows.size() == monitor.num_of_masters) {
			master_window_width = width_without_padding;
		} else {
			master_window_width = width_without_padding * monitor.master_percentage;
		}

		for (int i = 0; i < monitor.num_of_masters; ++i) {
			XMoveResizeWindow(display, monitor.windows[i].win, gap_size, (i + 1) * gap_size + i * master_window_height, master_window_width, master_window_height);
		}
	}

	if (monitor.windows.size() > monitor.num_of_masters) {
		int num_of_slaves = monitor.windows.size() - monitor.num_of_masters;
		int slaves_window_height = (monitor.height - (1 + num_of_slaves) * gap_size) / num_of_slaves;
		int slaves_window_width = width_without_padding - master_window_width;

		for (int i = 0; i < monitor.windows.size() - monitor.num_of_masters; ++i) {
			XMoveResizeWindow(display, monitor.windows[i].win, 2 * gap_size + master_window_width, (i + 1) * gap_size + i * slaves_window_height, slaves_window_width, slaves_window_height);
		}
	}

	XFlush(display);
}