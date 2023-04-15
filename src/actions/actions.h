#ifndef ACTIONS_H
#define ACTIONS_H

void spawn(const char *const *cmd);
void quit();
void killWindow();
void changeRatio(float increment);
void incrementMaster(int increment);

#endif /* ACTIONS_H */
