#include <cstdlib>
#include <cstring>
#include <iostream>

#include <X11/Xlib.h>

#include "config.h"
#include "eventHandlers.h"
#include "Monitors.h"
#include "utils/utils.h"

Display *display;
Monitor monitors[max_number_of_monitors];
Window root_window;

#ifdef XINERAMA
int amount_of_connected_monitors;
#endif


static void printVersion() {
	std::cout << "swm non working yet lol version.\n";
}

static void printUsage() {
	std::cout << "swm - simple window manager\n"
	             "Usage:\n"
	             "\tswm [OPTION]\n"
	             "\n"
	             "Options:\n"
	             "\t-h : Displays this message\n"
	             "\t-v : Displays the version\n";
}

static int errorOtherWmRunning(Display *display, XErrorEvent *event) {
	std::cerr << "Another wm is already running.\n";
	std::exit(-1);
	return -1;
}

int main(int argc, char **argv) {
	if (argc == 2) {
		if (std::strcmp(argv[1], "-v") == 0) {
			printVersion();
			return 0;
		} else if (std::strcmp(argv[1], "-h") == 0) {
			printUsage();
			return 0;
		} else {
			printUsage();
			return 1;
		}
	} else if (argc != 1) {
		printUsage();
		return 1;
	}

	display = XOpenDisplay(nullptr);

	if (display == nullptr) {
		std::cerr << "swm: failed to open display\n";
		return 2;
	}

	root_window = DefaultRootWindow(display);
	XSetErrorHandler(&errorOtherWmRunning);
	XSelectInput(display, root_window, SubstructureNotifyMask);

	updateKeybinds();
	updateMonitors();

	for (;;) {
		XEvent event;
		XNextEvent(display, &event);

		switch (event.type) {

		case KeyPress:
			onKeyPress(event.xkey);
			break;

		case CreateNotify:
			onCreateNotify(event.xcreatewindow);

		case EnterNotify:
		 	onEnterNotify(event.xcrossing);
		 	break;

		case MapNotify:
			onMapNotify(event.xmap);
			break;

		case MappingNotify:
			onMappingNotify(event.xmapping);
			break;

		case ConfigureNotify:
			onConfigureNotify(event.xconfigure);
			break;


		// Handle X events here
		default:
			std::cerr << "Unhandled event type: " << event.type << '\n';
			break;
		}
	}

	XCloseDisplay(display);
	return 0;
}
