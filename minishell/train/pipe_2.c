#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*Pipe - канал. Описание функции coming soon =)*/

int main(int argc, char *argv[])
{
	pid_t pid;
	int pipefd[2];
	char piperend[1024];
	char pipewend[1024];
	int size[2];
	int ret;
	
	memset(&size, 0, 8);
	ret = pipe(pipefd);
	if (ret == -1)
	{
		perror("Error: wrong pipe");
		exit (1);
	}
	pid = fork();
	if (!pid)
	{
		/*Child process*/
		close(pipefd[0]);
		printf("CHILD: Sup, It's child process, let's write something: ");
		scanf("%[^\n]%*c", pipewend);
		size[0] = strlen(pipewend);
		write(pipefd[1], &size[0], sizeof(int)); // size[0] + pipewend -> системный буфер -> size[1] + piperend. 
		// Порядок чтения точно такой же как и у записи
		write(pipefd[1], pipewend, size[0]);
		close(pipefd[1]);
	}
	else
	{
		/*Parent process*/
		close(pipefd[1]);
		printf("PARENT: Let's read pipe's writend.\n");
		read(pipefd[0], &size[1], sizeof(int));
		read(pipefd[0], piperend, size[1]);
		printf("PARENT: sizeof string: %d\n", size[1]);
		printf("PARENT: Child's string: %s\n", piperend);
	}
	return (0);
}
