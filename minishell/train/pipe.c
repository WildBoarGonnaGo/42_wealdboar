#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	/*pipe (канал) - файл, который является буфером с которого можно
	 считывать и в которой можно записывать*/
	int fd[2];
	if (pipe(fd) == -1)
		printf("An error occured with these file descriptors");
	return (0);
}
