/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/03/14 03:20:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_minishell_init(t_shell *obj, int argc,
		char **envp, char **argv)
{
	ft_memset(obj, 0, sizeof(*obj));
	obj->envp = envp;
	obj->argv = argv;
	obj->argc = argc;
	envp = sh_envp_dupl(*obj);
	obj->envp = envp;
	obj->status[1] = -1;
	obj->child = 1;
	ft_putstr_fd("minishell$ ", 1);
}

int		sh_minishell_body(t_shell *obj, int byte)
{
	obj->lst_flag[0] = 0;
	obj->roll = -1;
	obj->lst_start = NULL;
	if (!sh_line_err_parse(obj))
		obj->status[0] = obj->err_status;
	else if (ft_strncmp("", obj->line, 1))
		sh_line_ansys(obj);
	if (obj->status[1] >= 0 || !byte)
	{
		ft_putstr_fd("exit\n", 1);
		return (0);
	}
	ft_putstr_fd("minishell$ ", 1);
	sh_free_str(&obj->line);
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	int		byte;
	t_shell	obj;

	sh_minishell_init(&obj, argc, envp, argv);
	sh_signal_proc(&obj, 0);
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, signal_handle);
	while ((byte = sh_gnl(0, &obj.line)) > 0)
	{
		if (!sh_minishell_body(&obj, byte))
			break ;
	}
	sh_free_str(&obj.line);
	obj.status[1] = obj.status[0];
	alloc_free_2((void ***)&obj.envp);
	exit(obj.status[1]);
}
