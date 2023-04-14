#ifndef KEYBIND_H
#define KEYBIND_H

#include <X11/Xlib.h>

enum class Actions {
	spawn,
	quit,
	kill,
	changeRatio,
};

union Arg {
	const char *const *c;
	void *n;
	float f;
};

struct Keybind {
	KeySym keysym;
	Arg arg;
	unsigned int mod;
	Actions action_type;
};

#endif /* KEYBIND_H */
