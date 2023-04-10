#ifndef KEYBIND_H
#define KEYBIND_H

#include <X11/Xlib.h>

enum class Actions {
	spawn,
};

struct Keybind {
	unsigned int mod;
	KeySym keysym;
	void *arg;
	Actions action_type;
};

#endif /* KEYBIND_H */
