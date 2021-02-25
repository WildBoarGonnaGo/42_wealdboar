/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redir_list_fix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:03:03 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/25 20:34:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	sh_lst_delone(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}

void	sh_redir_list_fix(t_shell *obj)
{
	t_list	*crawler;
	t_list	*backup;

	crawler = obj->lst_start;
	/*if (!ft_strncmp(obj->cmd[0], "echo", 5))
		return ;*/
	while (crawler)
	{
		if (!ft_strncmp((char *)crawler->content, "<", 2) ||
		!ft_strncmp((char *)crawler->content, ">", 2) ||
		!ft_strncmp((char *)crawler->content, ">>", 3))
		{
			if (crawler == obj->lst_start)
			{
				obj->lst_start = crawler->next->next;
				sh_lst_delone(crawler->next);
				sh_lst_delone(crawler);
				crawler = obj->lst_start;
			}
			else
			{
				sh_lst_delone(crawler->next);
				sh_lst_delone(crawler);
				crawler = backup;
				crawler->next = backup->next->next->next;
			}
		}
		else
		{
			backup = crawler;
			crawler = crawler->next;
		}
	}
	obj->lst_head = backup;
}
