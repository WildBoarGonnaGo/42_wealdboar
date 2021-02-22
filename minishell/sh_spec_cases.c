/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_spec_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:02:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/22 10:30:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		err_set_var(int err_case, t_shell *obj, char *str)
{
	int pos;

	pos = ft_strnstr(obj->line, str, ft_strlen(obj->line)) - obj->line;
	if (pos < obj->err_pos)
	{
		obj->err_fst = err_case;
		obj->err_pos = ft_strnstr(obj->line, str, ft_strlen(obj->line)) - obj->line;
	}
	return (1);
}

void		err_output(t_shell obj)
{
	if (obj.err_fst == 1)
		ft_putstr_fd("minishell: syntax error near unexpected token `;;'\n", 2);
	else if (obj.err_fst == 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
	else if (obj.err_fst == 3)
		err_arrow_case(ft_strchr(ft_strchr(obj.line, '<'), '<'), 0, '<');
	else if (obj.err_fst == 4)
		err_arrow_case(ft_strchr(obj.line, '>'), 0, '>');
	/*else if (obj.err_fst == 5)
		ft_putstr_fd("minishell: export: `': not a valid identifier\n", 2);*/
	return ;
}

void		err_arrow_case(char *str, int count, char c)
{
	if (!*(str + count) || !(ft_strchr("<>", *(str + count))))
	{
		if (count == 4 && *(str + count - 1) == c && c == '<')
			ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
		else if (count == 5 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 2);
		else if (count == 5 && c == '<' && *(str + count - 1) == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `<>'\n", 2);
		else if (count >= 6 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<<'\n", 2);
		else if (count == 3 && *(str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
		else if (count >= 4 && *(str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 2);
		return ;
	}
	else if ((*str + count))
		err_arrow_case(str, ++count, c);
}

int			err_analisys(t_shell *obj)
{
	int	err_fst;
	int	err_status;

	err_fst = 0;
	obj->len = ft_strlen(obj->line);
	err_status = 0;
	obj->err_pos = SH_INT_MAX;
	obj->err_fst = 0;
	if (ft_strnstr(obj->line, ";;", obj->len) != NULL)
		err_status = err_set_var(1, obj, ";;");
	if (ft_strnstr(obj->line, "||", obj->len) != NULL)
		err_status = err_set_var(2, obj, "||");
	if (!ft_strncmp("<<<", obj->line, 4) || !ft_strncmp("<<", obj->line, 3) ||
	!ft_strncmp(">>", obj->line, 3) || !ft_strncmp(">", obj->line, 2) || 
	!ft_strncmp("<", obj->line, 2))
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 1);
	if (ft_strnstr(obj->line, "<<<<", obj->len) != NULL)
		err_status = err_set_var(3, obj, "<<<<");
	if (ft_strnstr(obj->line, ">>>", obj->len) != NULL)
		err_status = err_set_var(4, obj, ">>>");
	/*if (ft_strnstr(obj->line, " \"\" ", obj->len) != NULL)
	{
		if (!obj->err_fst)
		{
			obj->err_fst = 5;
			err_status = 2;
		}
	}*/
	err_output(*obj);
	return (err_status);
}


