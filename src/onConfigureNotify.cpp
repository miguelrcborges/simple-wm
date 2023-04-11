#include <iostream>

#include <X11/Xlib.h>

void onConfigureNotify(const XConfigureEvent &event) {
	std::cout << "[onConfigureNotify] code to be written.\n";
}
