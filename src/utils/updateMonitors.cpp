#include <X11/Xlib.h>
#include <X11/extensions/Xinerama.h>

#include "../config.h"

#include "../Monitors.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

void updateMonitors() {

#ifdef XINERAMA
	if (XineramaIsActive(display)) {
		int num_of_active_mons;
		XineramaScreenInfo *info = XineramaQueryScreens(display, &num_of_active_mons);

		for (int i = 0; i < num_of_active_mons && i < max_number_of_monitors; ++i) {
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
