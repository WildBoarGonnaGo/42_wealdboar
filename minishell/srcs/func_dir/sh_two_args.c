/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_two_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:19:45 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:02:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int		cd_two_args_body(t_shell *obj)
{
	obj->clean = obj->pipe_block[1];
	if (!(obj->pipe_block[1] = cd_two_args(obj, obj->pipe_block)))
	{
		sh_free_str((char **)&obj->backup);
		return (-1);
	}
	obj->argstr = obj->pipe_block[1];
	sh_free_str((char **)&obj->clean);
	return (1);
}
