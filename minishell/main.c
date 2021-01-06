/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:01:50 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/05 12:21:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int main(int argc, char *envp[])
{
	char	*line;

	line = NULL;
	write(1, "minishell: ", ft_strlen("minishell: "));
	while ((sh_gnl(0, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		write(1, "minishell: ", ft_strlen("minishell: "));
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	write(1, "exit\n", ft_strlen("exit\n"));
	return (0);
}
