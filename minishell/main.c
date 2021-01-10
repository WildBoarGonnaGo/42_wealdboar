/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/10 00:30:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"


int main(int argc, char **argv, char **envp)
{
	t_shell obj;

	obj.envp = envp;
	obj.argc = argc;
	obj.argv = argv;
	obj.line = NULL;
	write(1, "minishell$ ", ft_strlen("minishell$ "));
	while ((sh_gnl(0, &obj.line)) > 0)
	{
		sh_line_ansys(&obj);
		write(1, "minishell$ ", ft_strlen("minishell$ "));
		free(obj.line);
		obj.line = NULL;
	}
	if (obj.line)
	{
		free(obj.line);
		obj.line = NULL;
	}
	write(1, "exit\n", ft_strlen("exit\n"));
	return (0);
}
