#include "../config.h"

extern Display *display;
extern Window root_window;

void updateKeybinds() {
	XUngrabKey(display, AnyKey, AnyModifier, root_window);

	for (int i = 0; i < keybinds_length; ++i)
		XGrabKey(display, XKeysymToKeycode(display, keybinds[i].keysym), keybinds[i].mod, root_window, true,
		         GrabModeAsync, GrabModeAsync);
}
