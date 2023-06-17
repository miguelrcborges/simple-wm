#ifndef ACTIONS_H
#define ACTIONS_H

/**
 * Spawns a new process.
 * @param cmd Command to be ran. It should be an array of pointers nullptr terminated.
 */
void spawn(const char *const *cmd);

/**
 * Kills the wm
 */
void quit();

/**
 * Kill the current window in focus.
 */
void killClient();

/**
 * Change the master/stack clients ratio.
 * @param increment Rational on how much should be incremented (eg +0.05 increases 5%, -0.1 decreases 10%)
 */
void changeRatio(float increment);

/**
 * Change the ammount of master windows.
 * @param increment Number of master windows to be added/deleted.
 */
void incrementMaster(int increment);

/**
 * Change the active monitor to a different tag.
 * @param tag Targetted tag
 */
void changeTag(int tag);

/**
 * Change the client tag to a specific one.
 * @param tag Targetted tag
 */
void setClientTag(int tag);

/**
 * Toggles a specific tag of a client. If, at the end of the operation, the client would have no tags, there is no effect.
 * @param tag Targetted tag
 */
void toggleClientTag(int tag);

/**
 * Rotate the active clients positions n positions.
 * @param n Positions to rotate through (can be negative to rotate counterclockwise)
 */
void rotateStack(int tag);

/**
 * Set the current active window as tiled.
 */
void setTiled(void);

#endif /* ACTIONS_H */
