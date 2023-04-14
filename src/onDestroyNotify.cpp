#include "globals.h"
#include "utils/utils.h"


void onDestroyNotify(const XDestroyWindowEvent &event) {
#ifdef XINERAMA
	for (int i = 0; i < amount_of_connected_monitors; ++i) {
		for (auto ii = monitors[i].windows.begin(); ii != monitors[i].windows.end(); ++ii) {
			if (ii->win == event.window) {
				monitors[i].windows.erase(ii);
				return;
			}
		}
	}
#else
	for (auto i = monitors[0].windows.begin(); i != monitors[0].windows.end(); ++i) {
		if (i->win == event.window) {
			monitors[0].windows.erase(i);
			return;
		}
	}
#endif
}
