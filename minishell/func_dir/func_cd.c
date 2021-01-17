/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:28:01 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/17 20:51:44 by lchantel         ###   ########.fr       */
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
	int 	pos[2]; 
	char	buf[BUFFER_SIZE];
	char	*res;

	pos[0] = -1;
	while (++pos[0] < BUFFER_SIZE)
		buf[pos[0]] = 0;
	obj->clean = obj->line;
	obj->line = getcwd(buf, BUFFER_SIZE);
	if (obj->clean)
		free(obj->clean);
	obj->len = ft_strlen(obj->line);
	obj->clean = ft_strnstr(obj->line,
	cd_args[1], ft_strlen(obj->line));
	obj->len += ft_strlen(cd_args[2]) -
	ft_strlen(cd_args[1]);
	res = (char *)malloc(obj->len + 1);
	pos[0] = -1;
	while (++pos[0] < (obj->clean - obj->line));
		res[pos[0]] = obj->line[pos[0]];
	pos[1] = -1;
	while (++pos[1] < ft_strlen(cd_args[2]))
		res[pos[0]++] = obj->cd_args[2];
	while (pos[0] + pos[1] < ft_strlen(obj->line))
	{
		res[pos[0]] = obj->line;
	}
	return (0);
}

int 	change_dir(t_shell *obj, int indx)
{
	int		st;
	char	**cd_args;
	int		i;

	i = -1;
	cd_args = ft_split(obj->pipe_block[indx]);
	while (cd_args[++i])
		;
	if (i == 1)
		st = cd_no_args(obj);
	else
		st = chdir(obj->cd_args[1]);
	if (st)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
	}
	alloc_free_2((void **)cd_args);
	return (st);
}
