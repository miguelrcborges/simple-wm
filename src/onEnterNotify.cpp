#include <iostream>

#include <X11/Xlib.h>

void onEnterNotify(const XEnterWindowEvent &event) {
	std::cout << "[onEnterNotify] code to be written\n";
}
