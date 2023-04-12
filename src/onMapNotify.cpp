#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <iostream>

extern Display *display;

void onMapNotify(const XMapEvent &event) {
	std::cout << "Mapping requested" << std::endl;

	XMoveResizeWindow(display, event.window, 20, 20, 1900, 1060);
}
