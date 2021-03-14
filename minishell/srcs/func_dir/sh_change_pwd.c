/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_change_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:15:25 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:02:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sh_change_pwd_box(t_shell *obj, char *envpwd,
		int *info, char ***envp_cd)
{
	obj->clean2 = *envp_cd;
	*envp_cd = (char **)memrealloc(*envp_cd, sizeof(char *)
	* info[0], sizeof(char *));
	info[2] = !ft_strncmp(obj->envp[info[0]], envpwd, info[3]);
	if (info[2])
		info[1] = info[0];
	if (info[1] >= 0)
	{
		*(*envp_cd + info[1]) = (char *)malloc(ft_strlen(obj->cd_tmp)
		+ ++info[3] + 1);
		ft_strlcpy(*(*envp_cd + info[1]), envpwd, info[3]);
		ft_strlcat(*(*envp_cd + info[1]), "=", info[3] + 1);
		ft_strlcat(*(*envp_cd + info[1]), obj->cd_tmp, info[4]
		+ info[3] + 1);
		info[1] = -1;
	}
	else
		*(*envp_cd + info[0]) = ft_strdup(obj->envp[info[0]]);
}

char	**change_pwd(t_shell *obj, char *envpwd, char *dir)
{
	int		info[5];
	char	**envp_cd;

	info[3] = ft_strlen(envpwd);
	info[0] = -1;
	info[1] = -1;
	obj->cd_tmp = dir;
	info[4] = ft_strlen(obj->cd_tmp);
	envp_cd = NULL;
	while (obj->envp[++info[0]])
		sh_change_pwd_box(obj, envpwd, info, &envp_cd);
	envp_cd = (char **)memrealloc(envp_cd,
	sizeof(char *) * info[0], sizeof(char *));
	envp_cd[info[0]] = NULL;
	return (envp_cd);
}
