/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:53:12 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/18 13:26:49 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell_env(t_shell obj)
{
	int	i;

	i = -1;
	//dup2(obj.fd_recover[1], STDOUT_FILENO);
	while (obj.envp[++i])
	{
		if (ft_strchr(obj.envp[i], '='))
			write(1, obj.envp[i], ft_strlen(obj.envp[i]));
		write(1, "\n", 1);
	}
}
