/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fork_mem_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:18:09 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/10 21:32:55 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"

void	null_lst_unit(void *content)
{
	if (content)
	{
		free(content);
		content = 0x0;	
	}
}

void	sh_fork_mem_free(t_shell *obj)
{
	sh_free_str(&obj->line);
	alloc_free_2((void **)obj->cmd);
	alloc_free_2((void **)obj->pipe_block);
	ft_lstclear(&obj->lst_start, null_lst_unit);
	alloc_free_2((void **)obj->envp);
	alloc_free_2((void **)obj->bin_args);
	sh_free_str(&obj->bin_search);
	alloc_free_2((void **)obj->bin);
	alloc_free_2((void **)obj->clean2);
	sh_free_str((char **)&obj->clean);
	sh_free_str(&obj->clunit);
	sh_free_str(&obj->backup);
	alloc_free_2((void **)obj->tmp);
}
