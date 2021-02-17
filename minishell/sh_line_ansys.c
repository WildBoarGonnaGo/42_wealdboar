/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/17 22:35:30 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"

char	**lst_to_arr2(t_list *list, int start, int size)
{
	int		info[2];
	t_list	*walker;
	char	**res;

	info[0] = -1;
	info[1] = 0;
	walker = list;
	res = (char **)malloc(sizeof(char *) * size + 1);
	while (++info[0] < start && walker)
		walker = walker->next;
	while (info[0] < start + size && walker)
	{
		res[info[1]++] = ft_strdup((char *)walker->content);
		walker = walker->next;
		++info[0];
	}
	res[info[1]] = 0x0;
	return (res);
}

char	**set_arr2_strbound(char **arr, int *pos, char *str)
{
	char	**res;
	int		info[3];

	*pos = (*pos != -1) * *pos - (*pos == -1)
	+ (*pos != -1);
	info[0] = *pos;
	while (arr[++*pos])
	{
		if (!ft_strncmp(str, arr[*pos], ft_strlen(str)))
			break ;
	}
	info[1] = *pos - info[0] * (info[0] != -1);
	res = (char **)malloc(sizeof(char *) * (info[1] + 1));
	info[2] = -1;
	while (++info[0] < *pos)
		res[++info[2]] = ft_strdup(arr[info[0]]);
	res[info[0]] = 0x0;
	return (res);
}

void	sh_line_ansys(t_shell *obj)
{
	int		i;
	int 	j;
	//char	rbuf[4096] = {0};

	i = -1;	
	//obj->tmp = ft_split(obj->line, ';');
	obj->cmd_flag = (HANSEMI | HANPIPE);
	obj->fd_recover[0] = dup(STDIN_FILENO);
	obj->fd_recover[1] = dup(STDOUT_FILENO);
	while (obj->cmd_flag & HANSEMI)
	{
		sh_parcer(obj, obj->line);
		if (!ft_strncmp(";", (char *)obj->lst_head->content, 2))
			--obj->lst_flag[0];
		else
			obj->cmd_flag &= ~HANSEMI;
		++obj->roll;
		obj->cmd = lst_to_arr2(obj->lst_start, obj->lst_flag[1],
		obj->lst_flag[0]++ - obj->lst_flag[1]);
		/*if (!obj->line[obj->roll++])
			obj->cmd_flag &= ~HANSEMI;*/
		//obj->pipe_block = ft_split(obj->tmp[i], '|');
		j = -1;
		obj->cmd_flag |= HANPIPE;
		while (obj->cmd_flag & HANPIPE)
		{
			obj->pipe_block = set_arr2_strbound(obj->cmd, &j, "|");
			if (!obj->cmd[j])
				obj->cmd_flag &= ~HANPIPE;
			//obj->clean = obj->pipe_block[j - 1];
			//obj->pipe_block[j - 1] = ft_strtrim(obj->pipe_block[j - 1], " ");
			//free(obj->clean);
			//obj->clean = NULL;
			obj->len = ft_strlen(obj->pipe_block[0]) + 1;
			if (!ft_strncmp("cd", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("cd", obj->pipe_block[j - 1], 3) == -32*/)
				change_dir(obj);
			else if (!ft_strncmp("export", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("export", obj->pipe_block[j - 1], 7) == -32*/)
				ft_minishell_export(obj);
			else if (!ft_strncmp("unset", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("unset", obj->pipe_block[j - 1], 6) == -32*/)
				unset_envp(obj);
			else if (!ft_strncmp("echo", obj->pipe_block[0], 5)/* ||
			ft_strncmp("echo", obj->pipe_block[j - 1], 5) == -32*/)
				ft_minishell_echo(obj);
			else if (!ft_strncmp("env", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("env", obj->pipe_block[j - 1], 4) == -32*/)
				ft_minishell_env(obj);
			else if (!ft_strncmp("exit", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("exit", obj->pipe_block[j - 1], 5) == -32*/)
				obj->status[1] = sh_exit(obj);
			else if (!ft_strncmp("pwd", obj->pipe_block[0], obj->len)/* ||
			ft_strncmp("exit", obj->pipe_block[j - 1], 5) == -32*/)
				ft_minishell_pwd(obj);
			else
				sh_user_bin(obj);
		}
		dup2(obj->fd_recover[0], STDIN_FILENO);
		alloc_free_2((void **)obj->cmd);	
	}
	ft_lstclear(&obj->lst_start, free);
	//alloc_free_2((void **)obj->cmd);	
}
