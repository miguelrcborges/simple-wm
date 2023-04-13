#ifndef MONITORS_H
#define MONITORS_H

#include <X11/Xlib.h>

#include <vector>

struct Client {
	Window win;
	short width;
	short height;
	short x, y;
	short tags, state;
};

struct Monitor {
	std::vector<Client> windows;
	short width;
	short height;
	short x, y;
	short layout;
	short active_tags;
	float master_percentage;
	short num_of_masters;
};

#endif /* MONITORS_H */
