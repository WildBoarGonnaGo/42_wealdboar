/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:28:01 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/18 11:26:46 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		cd_no_args(t_shell *obj)
{
	int	i;
	int st;
	
	i = -1;
	obj->clean = obj->line;
	while (ft_strncmp(obj->envp[++i], "HOME", 4))
		;
	obj->line = ft_strdup(obj->envp[i] + 5);
	if (obj->clean)
		free(obj->clean);
	st = chdir(obj->line);
	return (st);
}

char	*cd_two_args(t_shell *obj, char **cd_args)
{
	char	buf[BUFFER_SIZE];
	char	*res;

	obj->clean = obj->line;
	ft_bzero(buf, BUFFER_SIZE);
	obj->line = getcwd(buf, BUFFER_SIZE);
	if (obj->clean)
		free(obj->clean);
	obj->len = ft_strlen(obj->line);
	if (!(obj->clean = ft_strnstr(obj->line,
	cd_args[1], ft_strlen(obj->line))))
	{
		write(2, "cd: not in pwd: ", ft_strlen("cd: not in pwd: "));
		write(2, cd_args[1], ft_strlen(cd_args[1]));
		write(2, "\n", 1);
		return (NULL);
	}
	obj->len += ft_strlen(cd_args[2]) - ft_strlen(cd_args[1]);
	res = (char *)malloc(obj->len + 1);
	ft_strlcpy(res, obj->line, (char *)obj->clean - obj->line);
	ft_strlcat(res, cd_args[2], ft_strlen(cd_args[2])); 
	ft_strlcat(res, obj->clean + ft_strlen(cd_args[1]), 
	ft_strlen(obj->clean + ft_strlen(cd_args[1])));
	return (res);
}

int 	change_dir(t_shell *obj, int indx)
{
	int		st;
	char	**cd_args;
	int		i;

	i = -1;
	st = 0;
	cd_args = ft_split(obj->pipe_block[indx], ' ');
	while (cd_args[++i])
		;
	if (i == 1)
		st = cd_no_args(obj);
	else if (i == 3)
	{
		obj->clean = cd_args[1];
		cd_args[1] = cd_two_args(obj, cd_args);
		free(obj->clean);
	}
	else if (cd_args[1])
		st = chdir(cd_args[1]);
	if (st)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
	}
	alloc_free_2((void **)cd_args);
	return (st);
}
