#ifndef GLOBALS_H
#define GLOBALS_H

#include <X11/Xlib.h>

#include "config.h"
#include "Monitor.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];
extern Window root_window;
extern Window last_focused;

#ifdef XINERAMA
extern int active_monitor;
extern int amount_of_connected_monitors;
#else
constexpr static int active_monitor = 0;
#endif

#endif
