/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:16:06 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:01:08 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cd_no_args(t_shell *obj)
{
	int	i;

	i = -1;
	obj->clean = obj->clunit;
	while (obj->envp[++i])
	{
		if (!ft_strncmp(obj->envp[i], "HOME", 5) ||
		ft_strncmp(obj->envp[i], "HOME", 5) == 61)
			break ;
	}
	obj->clunit = (obj->envp[i]) ? ft_strdup(obj->envp[i] + 5) :
	ft_strdup("");
	obj->if_child = ((!ft_strncmp("", obj->clunit, 1)) && (obj->envp[i] != 0));
	if (obj->clean)
		free(obj->clean);
	return (obj->clunit);
}

int		change_dir(t_shell *obj)
{
	int		st;
	int		i;
	char	**cd_clean_2;
	char	buf[BUFFER_SIZE];

	sh_change_dir_init(obj, &i, &st);
	if (i == 1)
		obj->argstr = cd_no_args(obj);
	else if (i == 3)
	{
		if (cd_two_args_body(obj) == -1)
			return (-1);
	}
	else if (obj->pipe_block[1] && (i == 2 || i >= 4))
		obj->argstr = obj->pipe_block[1];
	st = chdir(obj->argstr);
	obj->status[0] = (st != 0);
	obj->readenv = (obj->if_child && i == 1 && st);
	if ((st && !obj->readenv))
		change_dir_err_output(obj, i);
	else if ((!st && !obj->readenv) || !ft_strncmp("", obj->backup, 1))
		sh_change_dir_proc(obj, &cd_clean_2, buf);
	sh_free_str(&obj->backup);
	return (st);
}
