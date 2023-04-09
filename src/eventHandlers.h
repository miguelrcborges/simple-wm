#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include <X11/Xlib.h>

void onKeyPress(const XKeyEvent &event);
void onEnterNotify(const XEnterWindowEvent &event);

#endif
