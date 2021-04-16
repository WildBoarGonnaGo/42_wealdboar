#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int 	ft_strlen(char *s)
{
	int len;

	len = -1;
	while(*(s + ++len))
		;
	return (len);
}

void	cd_badargs_err_msg(void)
{
	write(2, "error: cd: bad arguments\n",
		ft_strlen("error: cd: bad arguments\n"));
}

void	cd_chdir_err_msg(char *msg)
{
	write(2, "error: cd: cannot change directory to ",
		ft_strlen("error: cd: cannot change directory to "));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	exec_err_msg(char *msg)
{
	write(2, "error: cannot execute ",
		ft_strlen("error: cannot execute "));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	err_fatal_msg(void)
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit (1);
}

void	ft_cd(char **line)
{
	int i = -1;

	while (line[++i])
		;
	if (i != 2)
		cd_badargs_err_msg();
	if (chdir(line[1]));
		cd_chdir_err_msg(line[1]);
}

int 	main(int argc, char *argv[], char *envp[])
{
	int		i = 0;
	int 	len = 0;
	char	**line = NULL;
	int		m = 0;
	int		is_pipe = 0;
	int		fd[2];
	int		save[2] = {0};
	int		opened = 0;
	pid_t	pid;
	int		status = 0;

	if (argc > 1)
	{
		while (++i < argc)
		{
			if (!strcmp(argv[i], ";") || !strcmp(argv[i], "|"))
				continue ;
			len = 0;
			while (argv[i + len] && strcmp(argv[i + len], ";") && strcmp(argv[i + len], "|"))
				++len;
			if (!(line = (char **)malloc(sizeof(char *) * (len + 1))))
				err_fatal_msg();
			line[len] = NULL;
			m = -1;
			while (++m < len)
				line[m] = argv[i++];
			is_pipe = (argv[i] && !strcmp(argv[i], "|"));
			if (!strcmp(line[0], "cd"))
			{
				ft_cd(line);
				continue ;
			}
			if (opened)
			{
				save[0] = dup(0);
				dup2(fd[0], 0);
				close(fd[0]);
			}
			if (is_pipe)
			{
				if (pipe(fd))
					exit_fatal();
				save[1] = dup(1);
				dup2(fd[1], 1);
				close(fd[1]);
			}
			pid = fork();
			if (pid < 0)
				exit_fatal();
			else if (!pid)
			{
				if (execve(line[0], line, envp))
					exec_err_msg(line[0]);
				exit (0);
			}
			else
				waitpid(pid, &status, 0);
			if (opened)
			{
				dup2(save[0], 0);
				close(save[0]);
				opened = 0;
			}
			if (is_pipe)
			{
				dup2(save[1], 1);
				close(save[1]);
				opened = 1;
			}
			free(line);
		}
	}
	return(0);
}