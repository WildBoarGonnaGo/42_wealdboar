/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:38:27 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/16 20:20:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_signal_proc(t_shell *obj, int sig)
{
	static t_shell *magic;

	if (!magic)
		magic = obj;
	else if (sig == SIGQUIT && !magic->if_child)
		write(1, "\b\b  \b\b", 6);
	else if (sig == SIGQUIT && magic->if_child)
	{
		write(2, "Quit: 3\n", ft_strlen("Quit: 3\n"));
		magic->status[0] = 128 + sig;
	}
	else if (sig == SIGINT && !magic->if_child)
	{
		write(1, "\b\b  \nminishell$ ", ft_strlen("\b\b  \nminishell$ ") + 1);
		magic->status[0] = 1;
	}
	else if (sig == SIGINT && magic->if_child)
	{
		write(1, "\n", 1);
		magic->status[0] = 128 + sig;
	}
}

void	signal_handle(int sig)
{
	sh_signal_proc(0x0, sig);
}
