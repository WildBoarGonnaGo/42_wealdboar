/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/16 21:45:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_minishell_pwd(t_shell obj)
{
	char	cwd[BUFFER_SIZE];

	dup2(obj.fd_recover[1], STDOUT_FILENO);
	getcwd(cwd, BUFFER_SIZE);
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	return (0);
}
