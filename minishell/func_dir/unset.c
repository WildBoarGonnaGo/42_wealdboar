/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:59:47 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/24 14:42:15 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char 	**arr_redef(char **mem, int indx)
{
	char 	**res;
	int		size;
	int		pos[2];

	size = -1;
	while (mem[++size])
		;
	pos[0] = -1;
	pos[1] = -1;
	res = (char **)malloc(sizeof(char *) * size);
	while (mem[++pos[0]])
	{
		if (pos[0] != indx)
			res[++pos[1]] = ft_strdup(mem[pos[0]]);
	}
	res[++pos[1]] = NULL;
	return (res); 
}

void 	rm_envp_var(t_shell *obj)
{
	int 	pos[2];
	char	*eq_char;
	pos[0] = 0;
	while (obj->cmd[++pos[0]])
	{
		if (check_export_input(obj->cmd[pos[0]], 0, obj->cmd[0], 0))
		{
			pos[1] = -1;
			while (obj->envp[++pos[1]])
			{
				eq_char = ft_strchr(obj->envp[pos[1]], '=');
				(eq_char) ? obj->len = eq_char - obj->envp[pos[1]]:
				ft_strlen(obj->envp[pos[1]]);
				if (!ft_strncmp(obj->envp[pos[1]], obj->cmd[pos[0]], obj->len + 1) ||
				ft_strncmp(obj->envp[pos[1]], obj->cmd[pos[0]], obj->len + 1) == 61)
				{
					obj->clean2 = obj->envp;
					obj->envp = arr_redef(obj->envp, pos[1]);
 					alloc_free_2((void **)obj->clean2);
					break ;
				}
			}
		}
	}
}

int 	unset_envp(t_shell *obj, int indx)
{
	obj->cmd = ft_split(obj->pipe_block[indx], ' ');
	obj->len = -1;
	while (obj->cmd[++obj->len])
		;
	if (obj->len > 1)
		rm_envp_var(obj);
	return (0);
}
