/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/21 14:54:04 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_minishell_pwd(t_shell obj, int indx)
{
	char	cwd[BUFFER_SIZE];

	if (!obj.pipe_block[indx + 1])
		dup2(obj.fd_recover[1], 1);
	getcwd(cwd, BUFFER_SIZE);
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	dup2(obj.fd_recover[1], STDOUT_FILENO);
	return (0);
}
