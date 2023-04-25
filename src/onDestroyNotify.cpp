#include "globals.h"
#include "utils/utils.h"


void onDestroyNotify(const XDestroyWindowEvent &event) {
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (auto ii = monitors[i].windows.begin(); ii != monitors[i].windows.end(); ++ii) {
			if (ii->win == event.window) {
				monitors[i].windows.erase(ii);
				return;
			}
		}
	}
}
