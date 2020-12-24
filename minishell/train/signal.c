#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void	handle_sigint(int signum)
{
	printf("signum(%d) | Process is terminated\n", signum);
	exit(signum);
}

int 	main(void)
{
	signal(SIGINT, handle_sigint);
	while(1)
	{
		printf("hello, wildboar\n");
		sleep(1);
	}
	return (0);
}

