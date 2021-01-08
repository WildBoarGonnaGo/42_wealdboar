/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/08 18:29:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_minishell_pwd(void)
{
	char	cwd[BUFFER_SIZE];

	getcwd(cwd, BUFFER_SIZE);
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	return (0);
}
