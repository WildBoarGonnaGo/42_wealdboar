/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/07 16:37:18 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./srcs/libft/libft.h"

typedef struct	s_gnl
{
	int 		st;
	char		buf[2048];
	int			byte;
	int			i;
}				t_gnl;

typedef struct	s_shell
{
	char	**arg;
	char	**env;
	char	**cmd;
	char	*prompt;
	char	*line;
	int		fd[2];
	pid_t	child;
	int		argc;
	char	loop;
	char	exit;
}				t_shell;


int sh_gnl(int fd, char **line);

#endif
