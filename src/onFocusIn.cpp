#include <X11/Xlib.h>

extern Window last_focused;

void onFocusIn(const XFocusChangeEvent &event) {
	last_focused = event.window;
}
