#include <iostream>
#include <unistd.h>
#include <spawn.h>

extern char **environ;

void exec(char **cmd) {
	posix_spawnp(NULL, cmd[0], NULL, NULL, cmd, environ);
}
