#include <iostream>
#include <spawn.h>
#include <unistd.h>

extern char **environ;

void spawn(char **cmd) {
	posix_spawnp(NULL, cmd[0], NULL, NULL, cmd, environ);
}
