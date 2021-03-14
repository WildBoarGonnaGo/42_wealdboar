/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_noarg_token_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:11:17 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:24:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		sh_token_status(char *str)
{
	return ((!(ft_strncmp(";", str, 2)) ||
	!(ft_strncmp("|", str, 2))
	|| !(ft_strncmp(">", str, 2))
	|| !(ft_strncmp("<", str, 2))
	|| !(ft_strncmp(">>", str, 3))));
}

int		sh_ambiguous_token(t_list *grabber)
{
	return ((!(ft_strncmp(">", (char *)grabber->content, 2)) ||
	!(ft_strncmp("<", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">>", (char *)grabber->content, 3))) &&
	*(char *)grabber->next->content == '$');
}
