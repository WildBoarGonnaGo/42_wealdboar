/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:07:18 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/06 21:09:27 by lcreola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1024

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

void	ft_checkargc(int argc);
void	ft_errors(int error);

#endif
