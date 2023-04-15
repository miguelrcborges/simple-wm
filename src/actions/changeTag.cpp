#include "../globals.h"
#include "../utils/utils.h"

void changeTag(int tag) {
	short new_tag = 1 << tag;
	if (monitors[active_monitor].active_tag == new_tag)
		return;

	monitors[active_monitor].active_tag = new_tag;
	checkWindowsTags(monitors[active_monitor]);
	rearrangeMonitor(monitors[active_monitor]);
}
