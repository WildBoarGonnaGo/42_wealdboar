/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:53:12 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/23 13:36:03 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell_env(t_shell obj, int indx)
{
	int	i;

	i = -1;
	if (!obj.pipe_block[indx + 1])
		dup2(obj.fd_recover[1], 1);
	while (obj.envp[++i])
	{
		if (ft_strchr(obj.envp[i], '='))
			write(1, obj.envp_secure[i], ft_strlen(obj.envp_secure[i]));
		write(1, "\n", 1);
	}
}
