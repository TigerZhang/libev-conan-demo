#include <ev.h>
#include <unistd.h>
#include <stdio.h> // for puts

// every watcher type has its own typedef'd struct
// with the name ev_TYPE
ev_io stdin_watcher;
ev_timer timeout_watcher;

// all watcher callbacks have a similar signature
// this callback is called when data is readable on stdin
static void stdin_cb(EV_P_ ev_io *w, int revents) {
	char s[64];
	int len = read(w->fd, s, 64);
	if (len > 0) {
		s[len] = 0;
		printf("recv:%s", s);
	}

}

// another callback, this time for a time-out
static void timeout_cb(EV_P_ ev_timer *w, int revents) {
	printf("Hello\n");
}

int main(void) {
	// use the default event loop unless you have special needs
	struct ev_loop *loop = EV_DEFAULT;

	ev_io_init(&stdin_watcher, stdin_cb, /*STDIN_FILENO*/0, EV_READ);
	ev_io_start(loop, &stdin_watcher);

	ev_timer_init(&timeout_watcher, timeout_cb, 2, 2);
	ev_timer_start(loop, &timeout_watcher);

	// now wait for events to arrive
	ev_run(loop, 0);

	// break was called, so exit
	return 0;
}
