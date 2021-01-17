#include "./minishell.h"

int sh_user_bin(t_shell *obj, int indx)
{
	int i;            
	int st;

	i = -1;
	st = 1;
	obj->len = 1;
	obj->line = NULL;
	obj->bin_args = execve_args(obj, indx);
	if (*obj->bin_search != '.' && *obj->bin_search != '/' \
	&& *obj->bin_search != '~')
	{
		st = 0;
		while (ft_strncmp(obj->envp[++i], "PATH", 4))
			;
		obj->bin = ft_split(obj->envp[i] + 5, ':');
		i = -1;
		while (obj->bin[++i])
		{
			if (!(obj->sh_dir = opendir(obj->bin[i])))
				break ;
			while ((obj->binary = readdir(obj->sh_dir)))
			{
				obj->len = ft_strlen(obj->bin_search) + 1;
				if (!(obj->len = ft_strncmp(obj->bin_search,
				(char *)obj->binary->d_name, obj->len)))
				{
					obj->line = ft_strdup(obj->bin[i]);
					obj->len = ft_strlen(obj->line);
					if (obj->line[obj->len - 1] != '/')
						obj->line = addchar(obj->line, '/');
					obj->clean = obj->line;
					obj->line = ft_strjoin(obj->line, obj->binary->d_name);
					obj->len = 0;
					free(obj->clean);	
					break ;
				}
			}
			closedir(obj->sh_dir);
			if (!obj->len)
				break ;
		}
	}
	if (!st)
	{
		if (!obj->line)
			obj->line = ft_strdup(obj->pipe_block[indx]);
		alloc_free_2((void **)obj->bin);
	}
	else 		
		obj->line = ft_strdup(obj->pipe_block[indx]);
	//st += execve(obj->line, obj->bin_args, obj->envp);
	st = execve(obj->line, obj->bin_args, obj->envp);
	if (st <= 0)
	{
		if (st == -1)
		{
			write(1, obj->line, ft_strlen(obj->line));
			write(2, ": command not found\n", ft_strlen(": command not found\n"));
		}
		else if (!st && (*obj->line == '.'
		|| *obj->line == '/' || *obj->line == '~'))
		{
			write(1, "minishell: ", ft_strlen("minishell: "));
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
		}
	}
	exit (0);
	//return (st);
}

/*st += execve(obj->line, obj->bin_args, obj->envp);
	if (st <= 0)
	{
		if (st == -1)
		{
			write(1, obj->line, ft_strlen(obj->line));
			write(2, ": command not found\n", ft_strlen(": command not found\n"));
		}
		else if (!st && (*obj->line == '.'
		|| *obj->line == '/' || *obj->line == '~'))
		{
			write(1, "minishell: ", ft_strlen("minishell: "));
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
		}
	}*/

/*obj->sh_pid[1] = fork();
	if (!obj->sh_pid[1])
	{
		st += execve(obj->line, obj->bin_args, obj->envp);
		if (st <= 0)
		{
			if (st == -1)
			{
				write(1, obj->line, ft_strlen(obj->line));
				write(2, "command not found\n", ft_strlen(": command not found\n"));

			}
			else if (!st && (*obj->line == '.'
			|| *obj->line == '/' || *obj->line == '~'))
			{
				write(1, "minishell: ", ft_strlen("minishell: "));
				write(2, strerror(errno), ft_strlen(strerror(errno)));
				write(1, "\n", 1);
			}
		}
		//return (st);
	}
	else
	{
		//waitpid(obj->sh_pid[1], &obj->status[1], 0);
		wait(&obj->status[1]);
		free(obj->line);
		obj->line = NULL;
	}*/

