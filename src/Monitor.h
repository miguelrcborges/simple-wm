#ifndef MONITORS_H
#define MONITORS_H

#include <X11/Xlib.h>

#include <vector>

enum class WindowState : unsigned char {
	neverMapped,
	tiled,
	floating,
	fullscreen,
	hidden_tiled,
	hidden_floating,
	hidden_fullscreen,
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
	short active_tag;
	float master_percentage;
	short num_of_masters;
	short stack_count;
};

#endif /* MONITORS_H */
