/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:28:01 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/24 11:19:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cd_no_args(t_shell *obj)
{
	int	i;
	
	i = -1;
	obj->clean = obj->line;
	while (ft_strncmp(obj->envp[++i], "HOME", 4))
		;
	obj->line = ft_strdup(obj->envp[i] + 5);
	if (obj->clean)
		free(obj->clean);
	return (obj->line);
}

char	**change_pwd(t_shell *obj, char *envpwd, char *dir)
{
	int		info[4];
	int		len;
	char	**envp_cd;

	len = ft_strlen(envpwd);
	info[0] = -1;
	info[1] = -1;
	envp_cd = NULL;
	while (obj->envp[++info[0]])
	{
		obj->clean2 = envp_cd;
		envp_cd = (char **)memrealloc(envp_cd, sizeof(char *) * info[0], sizeof(char *));
		info[2] = !ft_strncmp(obj->envp[info[0]], envpwd, len);
		if (info[2])
			info[1] = info[0];
		if (info[1] >= 0)
		{
			envp_cd[info[1]] = (char *)malloc(ft_strlen(dir) + ++len + 1);
			ft_strlcpy(envp_cd[info[1]], envpwd, len);
			ft_strlcat(envp_cd[info[1]], "=", len + 1);
			ft_strlcat(envp_cd[info[1]], dir, ft_strlen(dir) + len + 1);
			info[1] = -1;
		}
		else
			envp_cd[info[0]] = ft_strdup(obj->envp[info[0]]);
	}
	envp_cd = (char **)memrealloc(envp_cd, sizeof(char *) * info[0], sizeof(char *));
	envp_cd[info[0]] = NULL;
	return (envp_cd);
}

char	*cd_two_args(t_shell *obj, char **cd_args)
{
	char	*res;
	char	*line;
	char	*clean;

	line = (char *)malloc(256);
	ft_bzero(line, 256);
	getcwd(line, 256);
	obj->len = ft_strlen(line);
	if (!(clean = ft_strnstr(line, cd_args[1], ft_strlen(line))))
	{
		write(1, "cd: not in pwd: ", ft_strlen("cd: not in pwd: "));
		write(1, cd_args[1], ft_strlen(cd_args[1]));
		write(1, "\n", 1);
		return (NULL);
	}
	obj->len += ft_strlen(cd_args[2]) - ft_strlen(cd_args[1]) + 1;
	res = (char *)malloc(obj->len + 1);
	ft_strlcpy(res, line, (char *)clean - line + 1);
	ft_strlcat(res, cd_args[2], obj->len); 
	ft_strlcat(res, clean + ft_strlen(cd_args[1]), obj->len);	
	if (line)
		free(line);
	return (res);
}

int 	change_dir(t_shell *obj, int indx)
{
	int		st;
	char	**cd_args;
	int		i;
	char	**cd_clean_2;

	i = -1;
	st = 0;
	obj->backup = (char *)malloc(512);
	getcwd(obj->backup, 512);
	cd_args = ft_split(obj->pipe_block[indx], ' ');
	while (cd_args[++i])
		;
	if (i == 1)
		obj->argstr = cd_no_args(obj);
	else if (i == 3)
	{
		obj->clean = cd_args[1];
		if (!(cd_args[1] = cd_two_args(obj, cd_args)))
		{
			free(obj->backup);
			return (-1);
		}
		obj->argstr = cd_args[1];
		free(obj->clean);
	}
	else if (cd_args[1] && (i == 2 || i >= 4))
		obj->argstr = cd_args[1];
	st = chdir(obj->argstr);
	if (st)
	{
		write(1, "cd: ", ft_strlen("cd: "));
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, ": ", ft_strlen(": "));
		write(1, obj->argstr, ft_strlen(obj->argstr));
		write(1, "\n", 1);
	}
	else
	{
		cd_clean_2 = obj->envp;
		obj->envp = change_pwd(obj, "PWD", obj->argstr);
		if (cd_clean_2)
			alloc_free_2((void **)cd_clean_2);
		cd_clean_2 = obj->envp;
		obj->envp = change_pwd(obj, "OLDPWD", obj->backup);
		if (cd_clean_2)
			alloc_free_2((void **)cd_clean_2);
	}
	i = -1;
	free(obj->backup);
	alloc_free_2((void **)cd_args);
	return (st);
}
