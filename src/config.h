#ifndef CONFIG_H
#define CONFIG_H

#include <X11/keysym.h>

#include "Keybind.h"

#define TAGKEYS(KEY, TAG) \
	{ KEY, { .i = TAG }, Mod4Mask, Actions::changeTag },

constexpr static char *launch_term[] = {(char *)"xterm", nullptr};
constexpr static char *launcher[] = {(char *)"rofi", (char *)"-show", (char *)"drun", nullptr};
constexpr static char *screenshoot[] = {(char *)"/bin/sh", (char *)"-c", (char *)"maim -s -u | xclip -selection clipboard -t image/png -i", nullptr};

constexpr static Keybind keybinds[]{
	/* KEY, ARGUMENT, MODIFIER, ACTION */
	{ XK_Return, launch_term, Mod4Mask, Actions::spawn },
	{ XK_space, launcher, Mod4Mask, Actions::spawn },
	{ XK_s, screenshoot, Mod4Mask | ShiftMask, Actions::spawn },
	{ XK_c, nullptr, Mod4Mask, Actions::kill },
	{ XK_q, nullptr, Mod4Mask | ShiftMask, Actions::quit },
	{ XK_h, { .f = -0.05 }, Mod4Mask, Actions::changeRatio },
	{ XK_l, { .f = 0.05 }, Mod4Mask, Actions::changeRatio },
	{ XK_i, { .i = 1 }, Mod4Mask, Actions::incrementMaster },
	{ XK_d, { .i = -1 }, Mod4Mask, Actions::incrementMaster },
	TAGKEYS(XK_1, 1)
	TAGKEYS(XK_2, 2)
	TAGKEYS(XK_3, 3)
	TAGKEYS(XK_4, 4)
	TAGKEYS(XK_5, 5)
	TAGKEYS(XK_6, 6)
	TAGKEYS(XK_7, 7)
	TAGKEYS(XK_8, 8)
	TAGKEYS(XK_9, 9)
	TAGKEYS(XK_0, 0)
};

const static int gap_size = 10;

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
