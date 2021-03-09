/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_err_noarg_com.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:19:32 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/09 21:17:40 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int			sh_err_noarg_com(t_list *subj, t_shell *obj)
{
	t_list	*grabber;
	int		state[2];

	grabber = subj;
	//obj->err_status = 0;
	state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
	!(ft_strncmp("|", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">", (char *)grabber->content, 2)) ||
	!(ft_strncmp("<", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">>", (char *)grabber->content, 3)));
	if (!grabber)
		return (0);
	while (grabber->next)
	{
		state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->content, 3)));
		state[1] = (!(ft_strncmp(";", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->next->content, 3)));
		if (state[0] && state[1])
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd((char *)grabber->content, 2);
			ft_putstr_fd("'\n", 2);
			obj->err_status = 2;
			return (0);
		}
		if ((!(ft_strncmp(">", (char *)grabber->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->content, 3))) && 
		*(char *)grabber->next->content == '$')
		{
			obj->clean = sh_envp_search((char *)grabber->next->content, obj);
			if (!ft_strncmp((char *)obj->clean, "", 1))
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd((char *)grabber->next->content, 2);
				ft_putstr_fd(": ambiguous redirect\n", 2);
				obj->err_status = 1;
			}
			sh_free_str((char **)&obj->clean);
			if (obj->err_status)
				return (0);
		}
		grabber = grabber->next;
	}
	state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
	!(ft_strncmp("|", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">", (char *)grabber->content, 2)) ||
	!(ft_strncmp("<", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">>", (char *)grabber->content, 3)));
	if (state[0] && !grabber->next)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (!(ft_strncmp(">", (char *)grabber->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->content, 3)))
			ft_putstr_fd("newline", 2);
		else
			ft_putstr_fd((char *)grabber->content, 2);
		ft_putstr_fd("'\n", 2);
		obj->err_status = 2;
		return (0);
	}
	return (1);
}

