/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:33:39 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 23:13:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		main(int argc, char **argv)
{
	int		arg1;
	int		arg2;

	argc = 0;
	arg1 = ft_atoi(argv[argc + 1]);
	arg2 = ft_atoi(argv[argc + 3]);
	if (arg2 == 0 && (*argv[argc + 2] == '/' ||
				*argv[argc + 2] == '%'))
	{
		if (*argv[argc + 2] == '/')
			ft_putstr("Stop : division by zero");
		if (*argv[argc + 2] == '%')
			ft_putstr("Stop : modulo by zero");
		ft_putchar('\n');
		return (0);
	}
	ft_putnbr(ft_oper_exec(arg1, arg2, argv[argc + 2]));
	ft_putchar('\n');
	return (0);
}
