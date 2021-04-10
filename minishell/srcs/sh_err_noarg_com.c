/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_err_noarg_com.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:19:32 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/16 21:01:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		sh_ambiguous_redirect(t_shell *obj, t_list *grabber)
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
	return (obj->err_status);
}

int		sh_unex_token(t_shell *obj, char *str)
{
	ft_putstr_fd("minishell: syntax error near ", 2);
	ft_putstr_fd("unexpected token `", 2);
	if (!(ft_strncmp(">", str, 2)) ||
	!(ft_strncmp("<", str, 2)) ||
	!(ft_strncmp(">>", str, 3)))
		ft_putstr_fd("newline", 2);
	else
		ft_putstr_fd((char *)str, 2);
	ft_putstr_fd("'\n", 2);
	obj->err_status = 2;
	return (0);
}

int		sh_two_unex_token(t_shell *obj, char *str)
{
	ft_putstr_fd("minishell: syntax error near ", 2);
	ft_putstr_fd("unexpected token `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
	obj->err_status = 2;
	return (0);
}

int		sh_err_noarg_com(t_list *subj, t_shell *obj)
{
	t_list	*grabber;
	int		state[2];

	grabber = subj;
	state[0] = sh_token_status((char *)grabber->content);
	if (!grabber)
		return (0);
	while (grabber->next)
	{
		state[0] = sh_token_status((char *)grabber->content);
		state[1] = sh_token_status((char *)grabber->next->content);
		if (state[0] && state[1])
			return (sh_two_unex_token(obj, (char *)grabber->content));
		if (sh_ambiguous_token(grabber))
			if (sh_ambiguous_redirect(obj, grabber))
				return (0);
		grabber = grabber->next;
	}
	state[0] = sh_token_status((char *)grabber->content);
	if (state[0] && !grabber->next)
		return (sh_unex_token(obj, (char *)grabber->content));
	return (1);
}
