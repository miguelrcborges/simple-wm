#include <spawn.h>
#include <unistd.h>

extern char **environ;

void spawn(const char *const *cmd) {
	posix_spawnp(NULL, cmd[0], NULL, NULL, (char **)cmd, environ);
}
