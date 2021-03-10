/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/10 18:42:18 by lchantel         ###   ########.fr       */
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

char	**set_arr2_strbound(char **arr, int *pos, 
		char *str, t_shell *obj)
{
	char	**res;
	int		info[3];

	*pos = (*pos != -1) * *pos - (*pos == -1);
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
	{
		if (!sh_redirects(obj, &info[0]))
			res[++info[2]] = ft_strdup(arr[info[0]]);
		if (obj->err_fd[0])
			break ;
	}
	res[++info[2]] = 0x0;
	return (res);
}

void	sh_list_semicol_fix(t_shell *obj)
{
	char	*clean;
	t_list	*roll;

	roll = obj->lst_start;
	while (roll)
	{
		if (!ft_strncmp((char *)roll->content, "\";\"", 4))
		{
			clean = (char *)roll->content;
			roll->content = ft_strdup(";");
			sh_free_str(&clean);
		}
		roll = roll->next;
	}
}

void	sh_line_ansys(t_shell *obj)
{
	int		i;
	int 	j;

	i = -1;	
	obj->cmd_flag = (HANSEMI | HANPIPE);
	obj->fd_recover[0] = dup(STDIN_FILENO);
	obj->fd_recover[1] = dup(STDOUT_FILENO);
	while (obj->cmd_flag & HANSEMI)
	{
		if (!sh_parcer(obj))
			break ;
		if (!ft_strncmp(obj->line, "", 1))
			break ;
		if (!ft_strncmp(";", (char *)obj->lst_head->content, 2))
			--obj->lst_flag[0];
		else
			obj->cmd_flag &= ~HANSEMI;
		++obj->roll;
		sh_list_semicol_fix(obj);
		obj->cmd = lst_to_arr2(obj->lst_start, obj->lst_flag[1],
		obj->lst_flag[0]++ - obj->lst_flag[1]);
		j = -1;
		obj->cmd_flag |= HANPIPE;
		obj->err_fd[0] = 0;
		obj->err_fd[1] = 0;
		obj->fd_redir[0] = 0;
		obj->fd_redir[1] = 0;
		obj->err_fst = 0;
		while (obj->cmd_flag & HANPIPE)
		{	
			obj->pipe_block = set_arr2_strbound(obj->cmd, &j, "|", obj);
			if (!obj->cmd[j])
				obj->cmd_flag &= ~HANPIPE;
			obj->pipe_block = sh_pipe_block_fix(obj);
			if (obj->err_fd[0])
				break ;
			if (!obj->pipe_block[0])
			{
				obj->fd_redir[0] = 0;
				obj->fd_redir[1] = 0;
				continue ;
			}
			obj->len = ft_strlen(obj->pipe_block[0]) + 1;
			if (!ft_strncmp("cd", obj->pipe_block[0], obj->len))
				change_dir(obj);
			else if (!ft_strncmp("export", obj->pipe_block[0], obj->len))
				ft_minishell_export(obj);
			else if (!ft_strncmp("unset", obj->pipe_block[0], obj->len))
				unset_envp(obj);
			else if (!ft_strncmp("echo", obj->pipe_block[0], obj->len))
				ft_minishell_echo(obj);
			else if (!ft_strncmp("env", obj->pipe_block[0], obj->len))
				ft_minishell_env(obj);
			else if (!ft_strncmp("exit", obj->pipe_block[0], obj->len))
				sh_exit(obj);
			else if (!ft_strncmp("pwd", obj->pipe_block[0], obj->len))
				ft_minishell_pwd(obj);
			else
				sh_user_bin(obj);
			alloc_free_2((void **)obj->pipe_block);
			obj->err_fst = ((obj->cmd_flag & HANPIPE) != 0);
		}
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		if (obj->fd_redir[0])
			close(obj->fd_redir[0]);
		dup2(obj->fd_recover[0], STDIN_FILENO);
		dup2(obj->fd_recover[1], STDOUT_FILENO);
		alloc_free_2((void **)obj->cmd);
		obj->fd_redir[0] = 0;
		obj->fd_redir[1] = 0;
	}
	ft_lstclear(&obj->lst_start, free);
}
