#ifndef KEYBIND_H
#define KEYBIND_H

#include <X11/Xlib.h>

enum class Actions {
	spawn,
	quit,
	kill,
};

struct Keybind {
	KeySym keysym;
	void *arg;
	unsigned int mod;
	Actions action_type;
};

#endif /* KEYBIND_H */
