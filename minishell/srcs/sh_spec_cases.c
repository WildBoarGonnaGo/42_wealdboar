/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_spec_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:02:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:26:58 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		err_set_var(t_shell *obj, char *src, char *templ, int err_case)
{
	int pos;
	int len;

	len = ft_strlen(src);
	pos = ft_strnstr(src, templ, len) - src;
	if (pos < obj->err_pos)
	{
		obj->err_fst = err_case;
		obj->err_pos = pos;
	}
	return (1);
}

void	err_output(t_shell obj)
{
	if (obj.err_fst == 1)
		ft_putstr_fd("minishell: syntax error near unexpected token `;;'\n", 2);
	else if (obj.err_fst == 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
	else if (obj.err_fst == 3)
		err_arrow_case(ft_strchr(ft_strchr(obj.line, '<'), '<'), 0, '<');
	else if (obj.err_fst == 4)
		err_arrow_case(ft_strchr(obj.line, '>'), 0, '>');
	return ;
}

void	err_arrow_case(char *str, int count, char c)
{
	if (!*(str + count) || !(ft_strchr("<>", *(str + count))))
	{
		if (count == 4 && *(str + count - 1) == c && c == '<')
			ft_putstr_fd("minishell: syntax error near unexpected token `<'\n",
			2);
		else if (count == 5 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n",
			2);
		else if (count == 5 && c == '<' && *(str + count - 1) == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `<>'\n",
			2);
		else if (count >= 6 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<<'\n"
			, 2);
		else if (count == 3 && *(str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n",
			2);
		else if (count >= 4 && *(str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n",
			2);
		return ;
	}
	else if ((*str + count))
		err_arrow_case(str, ++count, c);
}
