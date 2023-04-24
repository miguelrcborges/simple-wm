#include "../globals.h"

#include <iostream>

void setWindowTag(int tag) {
	short new_tag = 1 << tag;
	if (new_tag == monitors[active_monitor].active_tag)
		return;

	if (!(new_tag & monitors[active_monitor].active_tag))
		XUnmapWindow(display, last_focused->win);

	std::cout << "still alive\n";
	last_focused->tags = new_tag;
}
