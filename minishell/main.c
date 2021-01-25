/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/25 21:05:15 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

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

int 	main(int argc, char **argv, char **envp)
{
	t_shell obj;
	obj.envp = envp;
	obj.argc = argc;
	obj.argv = argv;
	obj.line = NULL;
	envp = envp_dupl(obj);
	obj.envp = envp;
	obj.status[1] = -1;
	write(1, "minishell$ ", ft_strlen("minishell$ "));
	while ((sh_gnl(0, &obj.line)) > 0)
	{
		sh_line_ansys(&obj);
		if (obj.status[1] >= 0)
		{
			write(1, "exit\n", ft_strlen("exit\n"));
			break ;
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
	exit(obj.status[1]);
}
