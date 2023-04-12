#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <iostream>

#include "config.h"
#include "Monitors.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

#ifdef XINERAMA
extern int amount_of_connected_monitors;
#endif

void onCreateNotify(const XCreateWindowEvent &event) {
	Client newClient;
	newClient.win = event.window;

#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i) {
		if (event.x >= monitors[i].x && 
				event.x <= monitors[i].x + monitors[i].width &&
				event.y >= monitors[i].y &&
				event.y <= monitors[i].y + monitors[i].height
			) {
			monitors[i].windows.push_back(newClient);
			break;
		}
	}

#else
	monitors[0].windows.push_back(newClient);
#endif
}
