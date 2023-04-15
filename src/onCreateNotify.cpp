#include "globals.h"
#include <X11/Xutil.h>


void onCreateNotify(const XCreateWindowEvent &event) {

	Client newClient;
	newClient.win = event.window;
	newClient.state = WindowState::neverMapped;
	XSelectInput(display, event.window, FocusChangeMask);


	monitors[active_monitor].windows.push_back(newClient);
}
