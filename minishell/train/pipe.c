#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	/*pipe (канал) - файл, который является буфером с которого можно
	 считывать и в которой можно записывать*/
	int id;
	int fd[2];
	// fd[0] - read, fd[1] - write
	if (pipe(fd) == -1)
		printf("An error occured with these file descriptors");
	id = fork();
	if (!id)
	{
		close(fd[0]);
		int x;
		printf("CHILD: please input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	} 
	else 
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("PARRENT: got from child process: %d\n", y);
	}
	return (0);
}
