#include <X11/Xlib.h>

#include "actions/actions.h"

void onMappingNotify(const XMappingEvent &event) {
	switch (event.request) {
	case MappingKeyboard:
		updateKeybinds();
		break;
	}
}
