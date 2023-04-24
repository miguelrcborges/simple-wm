#include "globals.h"
#include "utils/utils.h"

void onButtonPress(const XButtonEvent &event) {
	if (event.subwindow == None || last_focused == nullptr)
		return;

	XSetWindowAttributes attr;
	if (event.button == Button1) { 
		cursor_action = cursorAction::Moving;
		attr.cursor = cursors[CURSOR_MOVE];
		XWarpPointer(display, None, last_focused->win, 0, 0, 0, 0, 0, 0);
	} else {
		cursor_action = cursorAction::Resizing;
		attr.cursor = cursors[CURSOR_RESIZE];
		XWarpPointer(display, None, last_focused->win, 0, 0, 0, 0, last_focused->width, last_focused->height);
	} 

	if (last_focused->state != WindowState::floating) {
		--monitors[active_monitor].stack_count;
		last_focused->state = WindowState::floating;
	}

	rearrangeMonitor(monitors[active_monitor]);
	XChangeWindowAttributes(display, root_window, CWCursor, &attr);
	XFlush(display);
}
