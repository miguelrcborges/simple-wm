#include <X11/XKBlib.h>
#include <X11/Xlib.h>
#include <X11/keysymdef.h>

#include "actions/actions.h"
#include "config.h"

extern Display *display;

void onKeyPress(const XKeyEvent &event) {
	KeySym pressed_key_keysym =
	    XkbKeycodeToKeysym(display, event.keycode, 0, 0);

	for (int i = 0; i < keybinds_length; ++i) {
		if ((pressed_key_keysym == keybinds[i].keysym) &&
		    (event.state == keybinds[i].mod)) {
			switch (keybinds[i].action_type) {
			case Actions::spawn:
				spawn((char **)keybinds[i].arg);
			}
		}
	}
}
