#include "../globals.h"

#include <X11/Xatom.h>

Atom getAtomProperty(Window window, Atom atom) {
	static Atom _XEMBED_INFO = XInternAtom(display, "_XEMBED_INFO", False);

	int di;
	unsigned long dl;
	unsigned char *p = NULL;
	Atom da, prop = None;

	if (XGetWindowProperty(display, window, atom, 0L, sizeof atom, False, XA_ATOM,
		&da, &di, &dl, &dl, &p) == Success && p) {
		prop = *(Atom *)p;
		if (da == _XEMBED_INFO && dl == 2)
			prop = ((Atom *)p)[1];
		XFree(p);
	}
	return prop;
}
