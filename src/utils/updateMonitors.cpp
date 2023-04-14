#include "../globals.h"

#include <X11/extensions/Xinerama.h>

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

#ifdef XINERAMA
extern int amount_of_connected_monitors;
#endif

void updateMonitors() {

#ifdef XINERAMA
	if (XineramaIsActive(display)) {
		XineramaScreenInfo *info = XineramaQueryScreens(display, &amount_of_connected_monitors);

		if (amount_of_connected_monitors > max_number_of_monitors)
			amount_of_connected_monitors = max_number_of_monitors;

		for (int i = 0; i < amount_of_connected_monitors; ++i) {
			monitors[i].width = info[i].width;
			monitors[i].height = info[i].height;
			monitors[i].x = info[i].x_org;
			monitors[i].y = info[i].y_org;
			monitors[i].num_of_masters = 1;
			monitors[i].master_percentage = 0.5;
		}

		XFree(info);
	} else
#endif
	{
		int screen = DefaultScreen(display);
		monitors[0].width = DisplayWidth(display, screen);
		monitors[0].height = DisplayHeight(display, screen);
		monitors[0].x = 0;
		monitors[0].y = 0;
		monitors[0].num_of_masters = 1;
		monitors[0].master_percentage = 0.5;
	}
}
