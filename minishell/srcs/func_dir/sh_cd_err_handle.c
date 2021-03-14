/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd_err_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:26:35 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:51:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_dir_err_output(t_shell *obj, int i)
{
	if (!ft_strncmp(obj->argstr, "", 1) && ((i == 1 &&
	!obj->if_child) || obj->env_is_home))
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	else
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(obj->argstr, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}

void	sh_cd_nonvalid_dir(t_shell *obj, char ***cd_clean_2)
{
	ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot ", 2);
	ft_putstr_fd("access parent directories: No such file or directory\n", 2);
	*cd_clean_2 = obj->envp;
	obj->clean = obj->backup;
	obj->envp = change_pwd(obj, "OLDPWD", obj->backup);
	obj->backup = ft_strjoin(obj->backup, obj->argstr);
	obj->envp = change_pwd(obj, "PWD", obj->backup);
	if (*cd_clean_2)
		alloc_free_2((void ***)cd_clean_2);
	sh_free_str((char **)&obj->clean);
}
