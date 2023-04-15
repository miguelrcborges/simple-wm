#include "../globals.h"
#include "../utils/utils.h"

void incrementMaster(int inc) {
	int tmp = monitors[active_monitor].num_of_masters + inc;
	if (tmp >= 0)
		monitors[active_monitor].num_of_masters = tmp;
	rearrangeMonitor(monitors[active_monitor]);
}
