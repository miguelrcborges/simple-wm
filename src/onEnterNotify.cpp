#include <iostream>

#include <X11/Xlib.h>

void onEnterNotify(const XEnterWindowEvent &event) {
	if (event.subwindow == None) {
		std::cout << "Rato criado\n";
	}
	std::cout << "[onEnterNotify] code to be written\n";
}
