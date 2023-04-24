#include "globals.h"
#include <X11/Xutil.h>

void onCreateNotify(const XCreateWindowEvent &event) {

	XSelectInput(display, event.window, FocusChangeMask);

	monitors[active_monitor].windows.emplace_back(Client {
			.win = event.window,
			.state = WindowState::neverMapped
			});
}
