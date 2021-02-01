/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/02/01 20:45:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include <signal.h>

char 	**envp_dupl(t_shell obj)
{
	int		size;
	char	**res;

	size = -1;
	while (obj.envp[++size])
		;
	res = (char **)malloc(sizeof(char *) * size + 1);
	size = -1;
	while (obj.envp[++size])
		res[size] = ft_strdup(obj.envp[size]);
	res[size] = NULL;
	return (res);
}

void	sh_func_quit(int sig)
{
	//SIG_IGN;
	sig_quit_st = sig;
	write(1, "\b\b  \b\b", 6);
}


int 	main(int argc, char **argv, char **envp)
{
	int	rage;

	t_shell obj;
	obj.envp = envp;
	obj.argc = argc;
	obj.argv = argv;
	obj.line = NULL;
	envp = envp_dupl(obj);
	obj.envp = envp;
	obj.status[1] = -1;
	obj.status[0] = 0;
	sig_state = 0;
	signal(SIGINT, sh_read_escape);
	write(1, "minishell$ ", ft_strlen("minishell$ "));
	while ((rage = sh_gnl(0, &obj.line)) > 0)
	{
		//obj.lst_start = sh_parcer(&obj, obj.line);
		sh_line_ansys(&obj);
		if (obj.status[1] >= 0 || !rage)
		{
			write(1, "exit\n", ft_strlen("exit\n"));
			break ;
		}
		if (sig_state)
		{
			sig_state = 0;
			if (obj.line)
				free(obj.line);
			write(1, "minishell$ ", ft_strlen("minishell$ "));
			obj.line = NULL;
			continue ;
		}
		else
			write(1, "minishell$ ", ft_strlen("minishell$ "));
		free(obj.line);
		obj.line = NULL;
	}
	if (obj.line)
	{
		free(obj.line);
		obj.line = NULL;
	}
	obj.status[1] = obj.status[0];
	exit(obj.status[1]);
}
