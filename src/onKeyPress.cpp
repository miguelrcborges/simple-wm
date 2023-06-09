#include "config.h"
#include "globals.h"

#include <X11/XKBlib.h>
#include <X11/keysymdef.h>

#include "actions/actions.h"
#include "utils/utils.h"

void onKeyPress(const XKeyEvent &event) {
	KeySym pressed_key_keysym = XkbKeycodeToKeysym(display, event.keycode, 0, 0);

	for (size_t i = 0; i < keybinds_length; ++i) {
		if ((pressed_key_keysym == keybinds[i].keysym) && (event.state == keybinds[i].mod)) {
			switch (keybinds[i].action_type) {
			case Actions::spawn:
				spawn(keybinds[i].arg.c);
				break;

			case Actions::kill:
				killClient();
				break;

			case Actions::quit:
				quit();
				break;

			case Actions::changeRatio:
				changeRatio(keybinds[i].arg.f);
				break;

			case Actions::incrementMaster:
				incrementMaster(keybinds[i].arg.i);
				break;

			case Actions::changeTag:
				changeTag(keybinds[i].arg.i);
				break;

			case Actions::setClientTag:
				setClientTag(keybinds[i].arg.i);
				break;

			case Actions::toggleClientTag:
				toggleClientTag(keybinds[i].arg.i);
				break;

			case Actions::rotateStack:
				rotateStack(keybinds[i].arg.i);
				break;

			case Actions::setTiled:
				setTiled();
				break;
			}
		}
	}
}
