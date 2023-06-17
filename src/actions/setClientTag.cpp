#include "../globals.h"

void setClientTag(int tag) {
	short new_tag = 1 << tag;
	if (new_tag == monitors[active_monitor].active_tag)
		return;

	if (!(new_tag & monitors[active_monitor].active_tag))
		XUnmapWindow(display, last_focused->win);

	last_focused->tags = new_tag;
}
