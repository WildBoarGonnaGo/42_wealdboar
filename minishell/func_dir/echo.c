/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:50:06 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/21 01:44:02 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		spec_case(char **str, t_shell *obj, int indx)
{
	if ((!ft_strncmp("-n", *str, 3) 
	|| ft_strncmp("-n", *str, 3) == -32) 
	&& indx == 1)
	{
		obj->eol = 0;
		return (0);
	}
	if (**str == '$')
	{
		obj->clean = *str;
		*str = sh_envp_search(*str + 1, *obj);
		free(obj->clean);
		obj->clean = NULL;
	}
	return (1);
}

void	ft_minishell_echo(t_shell *obj, int indx)
{
	int		i;
	char	**tmp;
	int		word;
	i = 0;

	word = 0;
	obj->eol = '\n';
	//dup2(obj->fd_recover[1], STDOUT_FILENO);
	tmp = ft_split(obj->pipe_block[indx], ' ');
	while (tmp[++i])
	{
		if (word)
			write(1, " ", 1);
		if (!spec_case(&tmp[i], obj, i))
			continue ;
		obj->len = ft_strlen(tmp[i]);
		write(1, tmp[i], obj->len);
		word += obj->len;
	}
	write(1, &obj->eol, 1);
	alloc_free_2((void **)tmp);
}
