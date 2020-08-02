/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:33:39 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 19:04:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
void	ft_putnbr(int num);
void	ft_putchar(int num);
void	ft_putstr(char *str);

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
