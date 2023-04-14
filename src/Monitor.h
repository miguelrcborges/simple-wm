#ifndef MONITORS_H
#define MONITORS_H

#include <X11/Xlib.h>

#include <vector>

enum class WindowState : unsigned char {
	invisible,
	tiled,
	floating,
	fulllscreen,
};

struct Client {
	Window win;
	short width, height;
	short x, y;
	short tags;
	WindowState state;
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
	short stack_count;
};

#endif /* MONITORS_H */
