#include "globals.h"

void onFocusIn(const XFocusChangeEvent &event) {
	last_focused = event.window;
}
