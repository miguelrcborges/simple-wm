#ifndef UTILS_H
#define UTILS_H 

#include "../Monitor.h"

/**
 * Disables all Keygrabs and reenables them.
 */
void updateKeybinds();

/**
 * Updates the monitors vector with the current active monitors.
 */
void updateMonitors();

/**
 * Rearranges the stack layout of a given monitor.
 * @param monitor Monitor whose stack layout will be updated.
 */
void rearrangeMonitor(Monitor &monitor);

/**
 * Drives through all clients in the given monitor. Unmaps windows which don't have the current monitor's
 * active tag and maps windows which have current monitor's tag incase they aren't mapped already.
 * @param monitor Monitor to check all clients' tags.
 */
void checkClientTags(Monitor &monitor);

#endif /* ACTIONS_H */
