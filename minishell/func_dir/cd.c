/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:16:06 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/24 21:13:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

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

char	**change_pwd(t_shell *obj, char *envpwd, char *dir)
{
	int		info[4];
	int		len;
	char	**envp_cd;

	len = ft_strlen(envpwd);
	info[0] = -1;
	info[1] = -1;
	envp_cd = NULL;;
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
		ft_putstr_fd("cd: not in pwd: ", 2);
		ft_putstr_fd(cd_args[1], 2);
		write(1, "\n", 2);
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

int 	change_dir(t_shell *obj)
{
	int		st;
	int		i;
	char	**cd_clean_2;
	char	buf[BUFFER_SIZE];

	i = -1;
	st = 0;
	obj->if_child = 0;
	obj->backup = sh_envp_search("PWD", obj);
	obj->if_child = 0;
	obj->clunit = 0x0;
	while (obj->pipe_block[++i])
		;
	if (i == 1)
		obj->argstr = cd_no_args(obj);
	else if (i == 3)
	{
		obj->clean = obj->pipe_block[1];
		if (!(obj->pipe_block[1] = cd_two_args(obj, obj->pipe_block)))
		{
			free(obj->backup);
			return (-1);
		}
		obj->argstr = obj->pipe_block[1];
		free(obj->clean);
	}
	else if (obj->pipe_block[1] && (i == 2 || i >= 4))
		obj->argstr = obj->pipe_block[1];
	st = chdir(obj->argstr);
	obj->status[0] = (st != 0);
	obj->readenv = (obj->if_child && i == 1 && st);
	if ((st && !obj->readenv))
	{
		if (!ft_strncmp(obj->argstr, "", 1) && ((i == 1 && !obj->if_child) 
		|| obj->env_is_home))
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
	else if ((!st && !obj->readenv) || !ft_strncmp("", obj->backup, 1))
	{
		cd_clean_2 = obj->envp;
		bzero(buf, BUFFER_SIZE);
		obj->envp = change_pwd(obj, "PWD", obj->argstr);
		if (cd_clean_2)
			alloc_free_2((void **)cd_clean_2);
		if (!getcwd(buf, BUFFER_SIZE))
		{
			ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n", 2);
			cd_clean_2 = obj->envp;
			obj->clean = obj->backup;
			obj->envp = change_pwd(obj, "OLDPWD", obj->backup);
			obj->backup = ft_strjoin(obj->backup, obj->argstr);
			obj->envp = change_pwd(obj, "PWD", obj->backup);
			if (cd_clean_2)
				alloc_free_2((void **)cd_clean_2);
			if (obj->clean)
			{
				free(obj->clean);
				obj->clean = NULL;
			}
		}
		else
		{
			cd_clean_2 = obj->envp;
			obj->envp = change_pwd(obj, "PWD", buf);
			if (cd_clean_2)
				alloc_free_2((void **)cd_clean_2);
			cd_clean_2 = obj->envp;
			obj->envp = change_pwd(obj, "OLDPWD", obj->backup);
			if (cd_clean_2)
				alloc_free_2((void **)cd_clean_2);
		}
	}
	i = -1;
	free(obj->backup);
	return (st);
}
