#include "globals.h"

void onPropertyNotify(const XPropertyEvent &event) {
#ifdef XINERAMA
	for (size_t i = 0; i < amount_of_connected_monitors; ++i) {
#else
	constexpr size_t i = 0; 
#endif
	
		for (size_t ii = 0; ii < monitors[i].windows.size(); ++ii) {

		}

#ifdef XINERAMA
	}
#endif
}
