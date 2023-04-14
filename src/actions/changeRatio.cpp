#include <X11/Xlib.h>

#include "../Monitor.h"
#include "../config.h"
#include "../utils/utils.h"

extern Display *display;
extern Monitor monitors[max_number_of_monitors];

#ifdef XINERAMA
extern int active_monitor;
#else
static constexpr int active_monitor = 0;
#endif

void changeRatio(float increment) {
	float tmp = monitors[active_monitor].master_percentage + increment;
	if (tmp >= 0.1 && tmp <= 0.9)
		monitors[active_monitor].master_percentage = tmp;
	rearrangeMonitor(monitors[active_monitor]);
}
