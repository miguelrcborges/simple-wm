#include "../globals.h"
#include "../utils/utils.h"

void changeRatio(float increment) {
	float tmp = monitors[active_monitor].master_percentage + increment;
	if (tmp >= 0.1 && tmp <= 0.9)
		monitors[active_monitor].master_percentage = tmp;
	rearrangeMonitor(monitors[active_monitor]);
}
