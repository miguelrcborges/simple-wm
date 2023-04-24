#include "../globals.h"

void toggleWindowTag(int tag) {
	short new_tag = last_focused->tags ^ (1 << tag);
	if (new_tag)
		last_focused->tags = new_tag;
	else
		return;

	if (!(new_tag ^ monitors[active_monitor].active_tag))
		XUnmapWindow(display, last_focused->win);
}
