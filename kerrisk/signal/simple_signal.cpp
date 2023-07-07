#include <iostream>
#include <signal.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>

static int kek;

#define DELETE_ON_LEFT "\033[K"

void handler(int sig) {
	std::cout << DELETE_ON_LEFT << "Simple Dimple " << ++kek << std::endl;
}

int main(void) {
	int c = 0;
	
	if (signal(SIGINT, handler) == SIG_ERR) {
		std::cerr << "can't handle signal 'SIGINT': " << strerror(errno) << std::endl;
		exit errno;
	}
	while(true) {
		std::cout << "Popit " << ++c << std::endl;
		sleep(1); 
	}
	return 0;
}
