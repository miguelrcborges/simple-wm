#include <cstdlib>
#include <cstring>
#include <iostream>

#include <X11/Xlib.h>
#include <X11/Xatom.h>

#include "Monitor.h"
#include "config.h"
#include "eventHandlers.h"
#include "utils/utils.h"

Atom test;
Display *display;
Monitor monitors[max_number_of_monitors];
Window root_window, wm_window;
Window last_focused;

#ifdef XINERAMA
int active_monitor = 0;
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

static int errorHandler(Display *display, XErrorEvent *event) {
	std::cerr << "[error] X error " << (int)event->error_code << " at " << (int)event->request_code << '\n';
	return -2;
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
	XSelectInput(display, root_window, SubstructureNotifyMask | PointerMotionMask);
	XSetErrorHandler(&errorHandler);

	wm_window = XCreateSimpleWindow(display, root_window, 0, 0, 1, 1, 0, 0, 0);
	
	// tell which root which window is the wm
	XChangeProperty(display, root_window, XInternAtom(display, "_NET_SUPPORTING_WM_CHECK", False),
			XA_WINDOW, 32, PropModeReplace, (unsigned char *) &wm_window, 1);
	// according to EWMH, the wm window must have it too
	XChangeProperty(display, wm_window, XInternAtom(display, "_NET_SUPPORTING_WM_CHECK", False),
			XA_WINDOW, 32, PropModeReplace, (unsigned char *) &wm_window, 1);
	// change wm name to show on neofetch :o
	XChangeProperty(display, wm_window, XInternAtom(display, "_NET_WM_NAME", False),
			XInternAtom(display, "UTF8_STRING", False), 8, PropModeReplace, (unsigned char *) "swm", 3);

	updateKeybinds();
	updateMonitors();

	for (;;) {
		XEvent event;
		XNextEvent(display, &event);

#ifdef _DEBUG
		std::cout << "event " << event.type << '\n';
#endif

		switch (event.type) {
		case MotionNotify:
			onMotionNotify(event.xmotion);
			break;

		case KeyPress:
			onKeyPress(event.xkey);
			break;

		case CreateNotify:
			onCreateNotify(event.xcreatewindow);
			break;

		case DestroyNotify:
			onDestroyNotify(event.xdestroywindow);
			break;

		case MapNotify:
			onMapNotify(event.xmap);
			break;

		case UnmapNotify:
			onUnmapNotify(event.xunmap);
			break;

		case MappingNotify:
			onMappingNotify(event.xmapping);
			break;

		case ConfigureNotify:
			onConfigureNotify(event.xconfigure);
			break;

		case FocusIn:
			onFocusIn(event.xfocus);
			break;

#ifdef _DEBUG
		// Handle X events here
		default:
			std::cerr << "Unhandled event type: " << event.type << '\n';
			break;
#endif
		}
	}

	XDestroyWindow(display, wm_window);
	XCloseDisplay(display);
	return 0;
}
