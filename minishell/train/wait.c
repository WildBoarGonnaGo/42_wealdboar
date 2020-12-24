#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/*
 Что происходит в main():



 p(fork()!=0)->else->printf("HP: hello from parrent\n")->cpid = wait(NULL)--------------------------------------------------->printf("HC: child has terminated\n")->printf("Bye\n");
                                                                         |                                                   |
																		 |                                                   |
																		 --->printf("HC: hello from child\n")->printf("Bye\n")
 фцнкция waitpid - аналогична функции wait только в качестве параметра указывается pid дочернего процесса
 * */
int main(void)
{
	pid_t cpid;

	if (!fork())
		printf("HC: hello from child\n");
	else
	{
		printf("HP: hello from parrent\n");
		cpid = wait(NULL);
		printf("HC: child has terminated\n");
	}
	printf("Bye\n");
	return (0);
}
