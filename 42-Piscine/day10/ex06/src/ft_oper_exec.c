/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 23:09:56 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 23:11:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_oper_exec(int a, int b, char *oper)
{
	if (*oper == '+')
		return (a + b);
	else if (*oper == '-')
		return (a - b);
	else if (*oper == '*')
		return (a * b);
	else if (*oper == '%')
		return (a % b);
	else if (*oper == '/')
		return (a / b);
	else
		return (0);
}
