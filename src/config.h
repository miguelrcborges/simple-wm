#ifndef CONFIG_H
#define CONFIG_H

#include <X11/keysym.h>

#include "Keybind.h"

constexpr static char *launch_term[] = {(char *)"xterm", NULL};

constexpr Keybind keybinds[]{
	/* MODIFIER, KEY, ARGUMENT, ACTION */
	{Mod4Mask, XK_Return, (void *)launch_term, Actions::spawn},
};

/* do not touch this */
constexpr int keybinds_length = sizeof(keybinds) / sizeof(keybinds[0]);

#endif /* CONFIG_H */
