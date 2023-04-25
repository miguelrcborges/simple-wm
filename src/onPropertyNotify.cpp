#include "globals.h"

void onPropertyNotify(const XPropertyEvent &event) {
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {

		}
	}
}
