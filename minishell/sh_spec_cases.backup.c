/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_spec_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:02:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/21 09:05:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		err_arrow_case(char *str, int count, char c)
{
	if (!*(str + count) || !(ft_strchr("<>", *(str + count))))
	{
		if (count == 5 && (*str + count - 1) == c && c == '<')
			ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
		else if (count == 6 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 2);
		else if (count == 6 && c == '<' && *(str + count - 1) == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `<>'\n", 2);
		else if (count >= 7 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<<'\n", 2);
		else if (count == 4 && (*str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
		else if (count >= 5 && (*str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 2);
		return ;
	}
	else if ((*str + count))
		err_arrow_case(str, ++count, c);
}

int			err_analisys(t_shell *obj)
{
	int	pos;
	int	err_fst;

	if ((obj->status[0] = (ft_strnstr("\"\"", obj->recycle, 2) != NULL)))
	{
		ft_putstr_fd("minishell: export: `': not a valid identifier", 2);
		pos = ft_strnstr("\"\"", obj->recycle, 2) - obj->recycle;
	}
	else if ((obj->status[0] = (ft_strnstr(obj->recycle, ";;", 2) != NULL)))
		ft_putstr_fd("minishell: syntax error near unexpected token `;;'\n", 2);
	/*else if ((obj->status[0] = !strnstr(obj->recycle, "|", 2)))
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);*/
	else if ((obj->status[0] = (ft_strnstr("||", obj->recycle, 2) != NULL/*&& ft_strlen(obj->recycle) >= 2*/)))
			ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
	else if ((obj->status[0] = (!ft_strncmp("<<<", obj->recycle, 4) || !ft_strncmp("<<", obj->recycle, 3) ||
	!ft_strncmp(">>", obj->recycle, 3) || !ft_strncmp(">", obj->recycle, 2) || 
	!ft_strncmp("<", obj->recycle, 2))))
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 1);
	else if ((obj->status[0] = !ft_strncmp("<<<<", obj->recycle, 4) && ft_strlen(obj->recycle) >= 4))
			err_arrow_case(obj->recycle, 4, '<');
	else if ((obj->status[0] = !ft_strncmp(">>>", obj->recycle, 3) && ft_strlen(obj->recycle) >= 3))
			err_arrow_case(obj->recycle, 3, '>');
	return (obj->status[0] + (!ft_strnstr(obj->recycle, "\"\"", 1)));
}


