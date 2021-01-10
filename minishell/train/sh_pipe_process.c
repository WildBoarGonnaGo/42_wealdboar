#include "../srcs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
	char	**tmp;
	char	**cmd;
	pid_t	pid;
	int		pipefd[2];
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error: wrong number of arguments\n",
		ft_strlen("Error: wrong number of arguments\n"));
		return (1);
	}
	tmp = ft_split(argv[i], '|');
	i = 0;
	while (tmp[++i])
	{
		cmd = ft_split()
		pipe(pipefd);
		pid = fork(); // pid процесса ребенка

		
		if (!pid)
		{
			close(pipefd[0]);
			dup2(1, pipefd[1]);
			execve()
		}
	}
	return (0);
}

execve("/usr/bin/cat", "./file.txt", env_kakoi_to)
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
