#include <X11/Xlib.h>
#include <X11/extensions/Xinerama.h>

#include "../config.h"

#include "../Monitors.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];
extern int amount_of_connected_monitors;

void updateMonitors() {

#ifdef XINERAMA
	if (XineramaIsActive(display)) {
		XineramaScreenInfo *info = XineramaQueryScreens(display, &amount_of_connected_monitors);

		if (amount_of_connected_monitors > max_number_of_monitors) amount_of_connected_monitors = max_number_of_monitors;

		for (int i = 0; i < amount_of_connected_monitors; ++i) {
			monitors[i].width = info[i].width;
			monitors[i].height = info[i].height;
			monitors[i].x = info[i].x_org;
			monitors[i].y = info[i].y_org;
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
	}
}
