/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/02/21 11:07:59 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"
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

void	sh_signal_proc(t_shell *obj, int sig)
{
	static t_shell *magic;
	
	if (!magic)
		magic = obj;
	else if (sig == SIGQUIT && !magic->if_child)
		write(1, "\b\b  \b\b", 6);
	else if (sig == SIGQUIT && magic->if_child)
	{
		write(2, "Quit: 3\n", ft_strlen("Quit: 3\n"));
		magic->status[2] = 128 + sig;
	}
	else if (sig == SIGINT && !magic->if_child)
	{
		write(1, "\b\b  \nminishell$ ", ft_strlen("\b\b  \nminishell$ ") + 1);
		magic->status[2] = 1;
	}
	else if (sig == SIGINT && magic->if_child)
	{
		write(1, "\n", 1);
		magic->status[2] = 128 + sig;
	}
}

void	signal_handle(int sig)
{
	sh_signal_proc(0x0, sig);
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
	obj.status[2] = 0;
	sig_state = 0;
	obj.child = 1;
	obj.if_child = 0;
	sh_signal_proc(&obj, 0);	
	//obj.lst_flag[1] = 0;
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, signal_handle);
	ft_putstr_fd("minishell$ ", 1);
	while ((rage = sh_gnl(0, &obj.line)) > 0)
	{
		obj.lst_flag[0] = 0;
		obj.roll = -1;
		obj.lst_start = NULL;
		if ((obj.err_status = err_analisys(&obj)))
			obj.status[0] = obj.err_status;
		else if (ft_strncmp("", obj.line, 1))
			sh_line_ansys(&obj);
		if (obj.status[1] >= 0 || !rage)
		{
			write(1, "exit\n", ft_strlen("exit\n"));
			break ;
		}
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
