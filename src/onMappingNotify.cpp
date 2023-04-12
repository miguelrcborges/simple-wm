#include <X11/Xlib.h>

#include "utils/utils.h"

void onMappingNotify(const XMappingEvent &event) {
	switch (event.request) {
	case MappingKeyboard:
		updateKeybinds();
		break;
	}
}
