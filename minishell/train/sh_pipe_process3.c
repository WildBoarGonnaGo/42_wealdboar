#include "../srcs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	if (mem)
	{	
		free(mem);
		mem = NULL;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char	**tmp;
	char	**cmd;
	char 	**arg;
	//char	**sh_envp;
	pid_t	pid;
	int		pipefd[2];
	int		pipefd2[2];
	char	rbuf[4096] = {0};
	int		i;
	int		len;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error: wrong number of arguments\n",
		ft_strlen("Error: wrong number of arguments\n"));
		return (1);
	}
	tmp = ft_split(argv[1], '|');
	i = 0;
	while (tmp[i++])
	{
		pipe(pipefd);
		pipe(pipefd2);
		pid = fork();	
		if (!pid)
		{
			if (!((i - 1) % 2))
			{
				dup2(pipefd2[1], 1);
				close(pipefd2[1]);
			}
			else
			{
				dup2(pipefd[1], 1);
				close(pipefd[1]);
			}
			close(pipefd[0]);
			close(pipefd[1]);
			close(pipefd2[0]);
			close(pipefd2[1]);
			cmd = ft_split(tmp[i - 1], ' ');
			len = -1;
			while (cmd[++len])
				;
			arg = (char **)malloc(sizeof(char *) * (len + 1));
			i = 0;
			arg[0] = argv[0];
			while (++i < len)
				arg[i] = ft_strdup(cmd[i]);
			arg[i] = NULL;
			execve(cmd[0], arg, envp);
			alloc_free_2((void **)cmd);
			alloc_free_2((void **)arg);
			exit (0);
		}
		else
		{
			if ((i - 1) % 2)
			{
				dup2(pipefd[0], 0);
				close(pipefd[0]);
			}
			else
			{
				dup2(pipefd2[0], 0);
				close(pipefd2[0]);
			}
			close(pipefd[0]);
			close(pipefd[1]);
			close(pipefd2[0]);
			close(pipefd2[1]);
			wait(NULL);
			if (!tmp[i])
				read(0, rbuf, 4096);	
		}
	}
	write(1, rbuf, 4096);
	return (0);
}
