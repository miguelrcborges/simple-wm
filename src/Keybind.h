#ifndef KEYBIND_H
#define KEYBIND_H

#include <X11/Xlib.h>

enum class Actions {
	spawn,
	quit,
	kill,
	changeRatio,
	incrementMaster,
	changeTag,
	setWindowTag,
	toggleWindowTag,
	rotateStack,
	setTiled,
};

union Arg {
	const char *const *c;
	void *n;
	float f;
	int i;
};

struct Keybind {
	KeySym keysym;
	Arg arg;
	unsigned int mod;
	Actions action_type;
};

#endif /* KEYBIND_H */
