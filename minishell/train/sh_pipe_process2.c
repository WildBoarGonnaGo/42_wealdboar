#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "../srcs/libft/libft.h"

int char_count(const char *s, char c)
{
	int i;
	int len;
	int res;

	len = ft_strlen(s);
	i = -1;
	res = 0;
	while (++i < len)
		res += (s[i] == c);
	return (res);
}

void alloc_free_2(void **mem)
{
	int i;

	i = -1;

	while (mem[++i] && mem)
	{
		free(mem[i]);
		mem[i] = NULL;
	}	
	free(mem);
	mem = NULL;
}

int main(int argc, char *argv[], char *envp[])
{
	int *pipes;
	char **cmd;
	char **args;
	char **tmp;
	int i;
	int status;
	int size;
	int buff;

	if (argc != 2)
	{
		write(1, "Error: wrong number of arguments\n",
		ft_strlen("Error: wrong number of arguments\n"));
		return (0);
	}
	i = char_count(argv[1], '|');
	pipes = (int *)malloc(sizeof(int) * (i + 1) * 2);
	size = i;
	i = -1;
	while (++i < size + 1)
		pipe(pipes + i * 2);
	i = 0;
	cmd = ft_split(argv[1], '|');
	while (cmd[i] && i <= size)
	{
		if (!fork())
		{
			if (!i)
				dup2(pipes[1], 1);
			else
			{
				dup2(pipes[2 * i + 1], 1);
				dup2(pipes[2 * i], 0);
			}
			i = -1;
			while (++i < (size + 1) * 2)
				close(pipes[i]);
			args = ft_split(cmd[i], ' ');
			size = -1;
			while (args[++size])
				;
			i = 0;
			tmp = (char **)malloc(sizeof(char *) * (size + 1));
			tmp[0] = argv[0];
			while (++i < size)
				tmp[i] = args[i];
			tmp[i] = NULL;
			execve(args[0], tmp, envp);
			alloc_free_2((void **)args);
			alloc_free_2((void **)tmp);
			exit (0);
		}
		else 
		{
			if (i != size)
				continue ;
			else
			{
				dup2(pipes[i], 0);
				i = -1;
				while (++i < (size + 1) * 2)
					close(pipes[i]);
				buff = size;
				args = ft_split(cmd[i], ' ');
				size = -1;
				while (args[++size])
					;
				i = 0;
				tmp = (char **)malloc(sizeof(char *) * (size + 1));
				tmp[0] = argv[0];
				while (++i < size)
					tmp[i] = args[i];
				tmp[i] = NULL;
				execve(args[0], tmp, envp);
				alloc_free_2((void **)args);
				alloc_free_2((void **)tmp);
				size = buff;
				i = size;
			}		
		}
		++i;
	}
	i = -1;
	while (++i < (size + 1) * 2)
		close(pipes[i]);
	i = -1;
	while (++i <= size)
		wait(&status);
}
