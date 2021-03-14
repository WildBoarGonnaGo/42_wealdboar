/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:41:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:02:19 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sh_change_pwd_appr(t_shell *obj, char *buf,
		char ***cd_clean_2)
{
	*cd_clean_2 = obj->envp;
	obj->envp = change_pwd(obj, "PWD", buf);
	if (*cd_clean_2)
		alloc_free_2((void ***)cd_clean_2);
	*cd_clean_2 = obj->envp;
	obj->envp = change_pwd(obj, "OLDPWD", obj->backup);
	if (*cd_clean_2)
		alloc_free_2((void ***)cd_clean_2);
}

void	sh_change_dir_proc(t_shell *obj, char ***cd_clean_2,
		char *buf)
{
	*cd_clean_2 = obj->envp;
	bzero(buf, BUFFER_SIZE);
	obj->envp = change_pwd(obj, "PWD", obj->argstr);
	if (*cd_clean_2)
		alloc_free_2((void ***)cd_clean_2);
	if (!getcwd(buf, BUFFER_SIZE))
		sh_cd_nonvalid_dir(obj, cd_clean_2);
	else
		sh_change_pwd_appr(obj, buf, cd_clean_2);
}

void	sh_change_dir_init(t_shell *obj, int *i, int *st)
{
	*i = -1;
	*st = 0;
	obj->if_child = 0;
	obj->backup = sh_envp_search("PWD", obj);
	obj->if_child = 0;
	obj->clunit = 0x0;
	while (obj->pipe_block[++*i])
		;
}
