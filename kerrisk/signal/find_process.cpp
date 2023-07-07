#include <iostream>
#include <signal.h>
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[]) {
	if (argc < 3 || (argc == 2 && !strcmp(argv[1], "--help"))) {
		std::cout << "Usage: ./test <pid> <signal>" << std::endl;
		return 0;
	}
	int pid = std::atoi(argv[1]);
	long sig = std::atol(argv[2]);
	int s = kill(pid, sig);
	if (sig != 0 && s == -1) {
		std::cerr << "error: can't send signal: " << strerror(sig) << std::endl;
		return -1;  
	}
	if (!sig) {
		if (!s) {
			std::cout << "Process with PID " << pid << " exists!" << std::endl;
			return 0;
		}
		else if (errno == EPERM) {
			std::cerr << "Process with PID " << pid
				<< " exists but we don't have permission to send signal to it "
				<< std::endl; 
		}
		else if (errno == ESRCH) {
			std::cerr << "Process with PID " << pid << " doesn't exist!" << std::endl;
			return -1; 
		}
		else  {
			std::cerr << "error: can't send signal: " << strerror(sig) << std::endl;
			return -1;  
		}
	}
	return 0;
}
