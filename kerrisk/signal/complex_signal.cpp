#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <cerrno>
#include <cstring>

void handler(int sig) {
	static int c;
	std::cout << "\b\b\033[K";
	if (sig == SIGINT) {
		c += 15;
		std::cout << "Social credit increased by 15 and now it's " << c << std::endl;
		return ;
	}
	std::cout << "Social credit -999999999999 and now you're scheduled for an execution tomorrow" << std::endl;
	exit(EXIT_SUCCESS);
}

int main(void) {
	if (signal(SIGINT, handler) == SIG_ERR) {
		std::cerr << "can't dispose signal handler: " << strerror(errno) << std::endl;
		return errno;
	}
	if (signal(SIGQUIT, handler) == SIG_ERR) {
		std::cerr << "can't dispose signal handler: " << strerror(errno) << std::endl;
		return errno;
	}
	while (true)
		pause();
	return 0;
}
