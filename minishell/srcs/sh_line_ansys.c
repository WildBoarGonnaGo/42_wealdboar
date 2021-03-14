/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:23:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_pipe_switch_oper(t_shell *obj)
{
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
}

int		sh_pipe_block_handle(t_shell *obj, int *j)
{
	obj->pipe_block = set_arr2_strbound(obj->cmd, j, "|", obj);
	if (!obj->cmd[*j])
		obj->cmd_flag &= ~HANPIPE;
	obj->pipe_block = sh_pipe_block_fix(obj);
	if (obj->err_fd[0])
		return (0);
	if (!obj->pipe_block[0])
	{
		obj->fd_redir[0] = 0;
		obj->fd_redir[1] = 0;
		return (1);
	}
	obj->len = ft_strlen(obj->pipe_block[0]) + 1;
	sh_pipe_switch_oper(obj);
	alloc_free_2((void ***)&obj->pipe_block);
	obj->err_fst = ((obj->cmd_flag & HANPIPE) != 0);
	return (1);
}

int		sh_semicol_block_prep(t_shell *obj, int *j)
{
	sh_parcer(obj);
	if (!ft_strncmp(obj->line, "", 1))
		return (0);
	if (!ft_strncmp(";", (char *)obj->lst_head->content, 2))
		--obj->lst_flag[0];
	else
		obj->cmd_flag &= ~HANSEMI;
	++obj->roll;
	sh_list_semicol_fix(obj);
	obj->cmd = lst_to_arr2(obj->lst_start, obj->lst_flag[1],
	obj->lst_flag[0]++ - obj->lst_flag[1]);
	*j = -1;
	obj->cmd_flag |= HANPIPE;
	obj->err_fd[0] = 0;
	obj->err_fd[1] = 0;
	obj->fd_redir[0] = 0;
	obj->fd_redir[1] = 0;
	obj->err_fst = 0;
	return (1);
}

void	sh_line_ansys(t_shell *obj)
{
	int	i;
	int j;

	i = -1;
	obj->cmd_flag = (HANSEMI | HANPIPE);
	obj->fd_recover[0] = dup(STDIN_FILENO);
	obj->fd_recover[1] = dup(STDOUT_FILENO);
	while (obj->cmd_flag & HANSEMI)
	{
		if (!sh_semicol_block_prep(obj, &j))
			break ;
		while (obj->cmd_flag & HANPIPE)
			if (!(sh_pipe_block_handle(obj, &j)))
				break ;
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		if (obj->fd_redir[0])
			close(obj->fd_redir[0]);
		dup2(obj->fd_recover[0], STDIN_FILENO);
		dup2(obj->fd_recover[1], STDOUT_FILENO);
		alloc_free_2((void ***)&obj->cmd);
		obj->fd_redir[0] = 0;
		obj->fd_redir[1] = 0;
	}
	ft_lstclear(&obj->lst_start, null_lst_unit);
}
