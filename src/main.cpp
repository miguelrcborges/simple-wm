#include <iostream>
#include <cstring>

void printVersion() {
	std::cout << "swm non working yet lol version.\n";
}

void printUsage() {
	std::cout << "swm - simple window manager\n"
		"Usage: \n"
		"\t-v : Displays the version\n";
}

int main(int argc, char **argv) {
	if (argc == 2 && std::strcmp(argv[1], "-v") == 0) {
		printVersion();
		return 0;
	} else if (argc != 1) {
		printUsage();
		return 0;
	}
}
