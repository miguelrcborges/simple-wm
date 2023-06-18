#include "../globals.h"
#include "utils.h"

void getWindowState(Client &c) {
	static Atom _NET_WM_STATE = XInternAtom(display, "_NET_WM_STATE", False);
	static Atom _NET_WM_WINDOW_TYPE = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
	static Atom _NET_WM_STATE_FULLSCREEN = XInternAtom(display, "_NET_WM_STATE_FULLSCREEN", False);
	static Atom _NET_WM_WINDOW_TYPE_DIALOG = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DIALOG", False);

	Atom window_type = getAtomProperty(c.win, _NET_WM_WINDOW_TYPE);
	Atom window_state = getAtomProperty(c.win, _NET_WM_STATE);

	if (window_state == _NET_WM_STATE_FULLSCREEN)
		c.state = WindowState::fullscreen;

	if (window_type == _NET_WM_WINDOW_TYPE_DIALOG)
		c.state = WindowState::floating;
}
