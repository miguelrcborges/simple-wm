#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include <X11/Xlib.h>

void onMotionNotify(const XMotionEvent &event);
void onKeyPress(const XKeyEvent &event);
void onCreateNotify(const XCreateWindowEvent &event);
void onDestroyNotify(const XDestroyWindowEvent &event);
void onMapNotify(const XMapEvent &event);
void onUnmapNotify(const XUnmapEvent &event); 
void onMappingNotify(const XMappingEvent &event);
void onConfigureNotify(const XConfigureEvent &event);
void onEnterNotify(const XCrossingEvent &event);
void onButtonPress(const XButtonEvent &event);
void onButtonRelease(const XButtonEvent &event);

#endif
