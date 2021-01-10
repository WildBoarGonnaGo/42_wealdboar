#include <sys/types.h>                  // для fork(), opendir(), readdir(), wait()
#include <stdio.h>                      // printf=)
#include <dirent.h>                     // для структуры dirent, opendir(), readdir()
#include <stdlib.h>                     // для malloc и exit
#include "./srcs/libft/libft.h"        // Заголовочный файл libft, ваш путь может отличаться=)
#include <unistd.h>                     // для write(), fork() и execve()
#include <sys/wait.h>                   // для wait()
#include <errno.h>                      // для errno
#include <string.h>                     // для strerror
#include "./minishell.h"

int sh_user_bin(t_shell *obj, int indx)
{
	int i;            
	int st;

	errno = 0;
	i = -1;
	st = 1;
	obj->len = 1;
	obj->line = NULL;
	if (*obj->tmp[indx] != '.' && *obj->tmp[indx] != '/' && *obj->tmp[indx] != '~')
	{
		st = 0;
		while (ft_strncmp(obj->envp[++i], "PATH", 4))
			;
		obj->bin = ft_split(obj->envp[i] + 5, ':');
		i = -1;
		while (obj->bin[++i])
		{
			if (!(obj->sh_dir = opendir(obj->bin[i])))
			{
				write(1, "minishell: ", ft_strlen("minishell: "));
				write(2, strerror(errno), ft_strlen(strerror(errno)));
				write(1, "\n", 1);
				exit (1);
			}
			while ((obj->binary = readdir(obj->sh_dir)))
			{
				obj->len = ft_strlen(obj->tmp[indx]) + 1;
				if (!(obj->len = ft_strncmp(obj->tmp[indx],
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
			obj->line = ft_strdup(obj->tmp[indx]);
		alloc_free_2((void **)obj->bin);
	}
	else 		
		obj->line = ft_strdup(obj->tmp[indx]);
	obj->child = fork();
	if (!obj->child)
	{
		st += execve(obj->line, obj->argv, obj->envp);
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
		return (st);
	}
	else
	{
		wait(NULL);
		free(obj->line);
		obj->line = NULL;
	}
	return (0);
}


