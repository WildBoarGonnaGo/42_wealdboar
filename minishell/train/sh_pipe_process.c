#include "../srcs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
	char	**tmp;
	char	**cmd;
	char 	**arg;
	char	**sh_envp;
	pid_t	pid;
	pid_t	pid_2;
	int		pipefd[2];
	int		pipefd2[2];
	char	rbuf[4096] = {0};
	char	wbuf[4096];
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
		pid = fork();	
		if (!pid)
		{	
			close(pipefd[0]);
			if (i != 1)
			{
				close(pipefd2[1]);
				dup2(pipefd2[0], 0);
			}
			cmd = ft_split(tmp[i - 1], ' ');
			len = -1;
			while (cmd[++len])
				;
			arg = (char **)malloc(sizeof(char *) * len + 1);
			i = 0;
			arg[0] = argv[0];
			while (++i < len)
				arg[i] = ft_strdup(cmd[i]);
			arg[i] = NULL;
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			execve(cmd[0], arg, envp);
			if (i != 1)
				close(pipefd2[0]);	
			exit (0);
		}
		else
		{
			close(pipefd[1]);
			wait(NULL);
			len = -1;	
			while (++len < 4096)
				rbuf[len] = 0;
			read(pipefd[0], rbuf, 4096);
			close(pipefd[0]);
			pipe(pipefd2);
			pid_2 = fork();
			if (!pid_2)
			{
				close(pipefd2[0]);
				write(pipefd2[1], rbuf, 4096);
				close(pipefd2[1]);
				exit (0);
			}
			wait(NULL);	
		}
	}
	close(pipefd2[0]);
	write(1, rbuf, 4096);
	return (0);
}

/*char **sh_pipe(t_shell *obj)
{
	char	**data;
	int		pos[2];

	obj->pipes = ft_split(obj);
	pos[0] = 0;
	pipe(obj->fd);
	data = NULL;
	while (pipes[++pos[0]])
	{
		obj->child = fork();
		if (!obj->child)
		{
			close(obj->fd[0]);
			//char **sh_line_proc(char *pipe_line, char **data) - функция которая возвращает результат в виде двойного массива
			data = sh_line_proc(pipes[pos[0] - 1], data);
			write(obj->fd[1], data, sizeof(char **));
			close(ojb->fd[1]);
		}
		else
		{
			close(obj->fd[1]);
			read(obj->fd[0], data, sizeof(char **));
			close(ojb->fd[0]);
		}
	}
	return (data);
}*/
