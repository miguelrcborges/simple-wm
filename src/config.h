#ifndef CONFIG_H
#define CONFIG_H

#include <X11/keysym.h>

#include "Keybind.h"

constexpr static char *launch_term[] = {(char *)"xterm", nullptr};
constexpr static char *launcher[] = {(char *)"rofi", (char *)"-show", (char *)"drun", nullptr};
constexpr static char *screenshoot[] = {(char *)"/bin/sh", (char *)"-c", (char *)"maim -s -u | xclip -selection clipboard -t image/png -i", nullptr};

constexpr Keybind keybinds[]{
	/* MODIFIER, KEY, ARGUMENT, ACTION */
	{Mod4Mask, XK_Return, (void *)launch_term, Actions::spawn},
	{Mod4Mask, XK_space, (void *)launcher, Actions::spawn},
	{Mod4Mask | ShiftMask, XK_s, (void *)screenshoot, Actions::spawn},
};

/* do not touch this */
constexpr int keybinds_length = sizeof(keybinds) / sizeof(keybinds[0]);

#endif /* CONFIG_H */
