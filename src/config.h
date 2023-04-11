#ifndef CONFIG_H
#define CONFIG_H

#include <X11/keysym.h>

#include "Keybind.h"

constexpr static char *launch_term[] = {(char *)"xterm", nullptr};
constexpr static char *launcher[] = {(char *)"rofi", (char *)"-show", (char *)"drun", nullptr};
constexpr static char *screenshoot[] = {(char *)"/bin/sh", (char *)"-c", (char *)"maim -s -u | xclip -selection clipboard -t image/png -i", nullptr};

constexpr static Keybind keybinds[]{
	/* MODIFIER, KEY, ARGUMENT, ACTION */
	{Mod4Mask, XK_Return, (void *)launch_term, Actions::spawn},
	{Mod4Mask, XK_space, (void *)launcher, Actions::spawn},
	{Mod4Mask | ShiftMask, XK_s, (void *)screenshoot, Actions::spawn},
};


/* Leave this uncommented for multi-monitor support.
 *
 * If you are on single monitor you can comment this and remove -lXinerama
 * from the links variable on the makefile.
 */
#define XINERAMA

#ifdef XINERAMA
constexpr static int max_number_of_monitors = 2;
#endif

/* do not edit the code bellow this */
constexpr int keybinds_length = sizeof(keybinds) / sizeof(keybinds[0]);

#ifndef XINERAMA
constexpr static int max_number_of_monitors = 1;
#endif

#endif /* CONFIG_H */
