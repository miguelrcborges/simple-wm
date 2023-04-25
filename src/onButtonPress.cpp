#include "globals.h"
#include "utils/utils.h"

void onButtonPress(const XButtonEvent &event) {
	constexpr int mouse_mask = ButtonPressMask | ButtonReleaseMask | PointerMotionMask;

	if (event.subwindow == None || last_focused == nullptr)
		return;

	XSetWindowAttributes attr;
	if (event.button == Button1) { 
		cursor_action = cursorAction::Moving;
		attr.cursor = cursors[CURSOR_MOVE];
		XWarpPointer(display, None, last_focused->win, 0, 0, 0, 0, 0, 0);
		XGrabPointer(display, root_window, False, mouse_mask, GrabModeAsync, GrabModeAsync, None, cursors[CURSOR_MOVE], CurrentTime);
	} else {
		cursor_action = cursorAction::Resizing;
		attr.cursor = cursors[CURSOR_RESIZE];
		XWarpPointer(display, None, last_focused->win, 0, 0, 0, 0, last_focused->width, last_focused->height);
		XGrabPointer(display, root_window, False, mouse_mask, GrabModeAsync, GrabModeAsync, None, cursors[CURSOR_RESIZE], CurrentTime);
	} 

	if (last_focused->state != WindowState::floating) {
		if (last_focused->state == WindowState::tiled)
			--monitors[active_monitor].stack_count;
		last_focused->state = WindowState::floating;
	}

	rearrangeMonitor(monitors[active_monitor]);
}
