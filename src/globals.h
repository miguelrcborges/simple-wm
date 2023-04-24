#ifndef GLOBALS_H
#define GLOBALS_H

#include <X11/Xlib.h>

#include "config.h"
#include "Monitor.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];
extern Window root_window, wm_window;
extern Client *last_focused;

enum { CURSOR_NORMAL, CURSOR_RESIZE, CURSOR_MOVE };
extern Cursor cursors[3];

enum class cursorAction : unsigned char {
	NoAction,
	Moving,
	Resizing,
};
extern cursorAction cursor_action;

#ifdef XINERAMA
extern int active_monitor;
extern int amount_of_connected_monitors;
#else
constexpr static int active_monitor = 0;
#endif

#endif
