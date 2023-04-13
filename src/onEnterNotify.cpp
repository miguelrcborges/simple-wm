#include <iostream>

#include <X11/Xlib.h>

void onEnterNotify(const XEnterWindowEvent &event) {
#ifdef _DEBUG
	std::cout << "[onEnterNotify] code to be written\n";
#endif
}
