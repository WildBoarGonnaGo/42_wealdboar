#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc , char *argv[])
{
	int status;
	int i;

	char *cat_args[] = { "cat", "./file.txt", NULL };
	char *head_args[] = { "head", "-5", NULL };
	char *tail_args[] = { "tail", "-2", NULL };

	int pipes[4];
	pipe(pipes);
	pipe(pipes + 2);
	if (!fork())
	{
		i = -1;
		dup2(pipes[1], 1);
		while (++i < 4)
			close(pipes[i]);
		execvp(*cat_args, cat_args);
	}
	else
	{
		if (!fork())
		{
			i = -1;
			dup2(pipes[0], 0);
			dup2(pipes[3], 1);
			while (++i < 4)
				close(pipes[i]);
			execvp(*head_args, head_args);
		}
		else
		{
			i = -1;
			dup2(pipes[2], 0);
			while (++i < 4)
				close(pipes[i]);
			execvp(*tail_args, tail_args);
		}
	}
	/*i = -1;
	while (++i < 4)
		close(pipes[i]);*/
	i = -1;
	while (++i < 3)
		wait(&status);
}
