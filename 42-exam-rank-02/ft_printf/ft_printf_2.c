/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 22:40:40 by wealdboar         #+#    #+#             */
/*   Updated: 2020/11/29 15:22:28 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

typedef struct	exam_flags
{
	int			i;
	int			len;
	int			width;
	int			if_precis;
	int			precis;
	int			neg;
	int			zero;
	int			output;
	va_list 	list;
}				_obj;

void			ft_init_roll(_obj *flags)
{
	flags->i = 0;
	flags->output = 0;
}

void			ft_init_strct(_obj *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->if_precis = 0;
	flags->precis = 0;
	flags->neg = 0;
	flags->zero = 0;
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr_len(const char *s, const int max_i)
{
	int	i;

	i = 0;
	while (i < max_i && *(s + i))
		ft_putchar(*(s + i++));
}

int				ft_strlen(const char *s)
{
	int size;

	size = -1;
	if (!s)
		return (0);
	while (*(s + ++size))
		;
	return (size);
}

int				ft_numlen_base(long num, int base)
{
	int	i;

	i = 0;
	if (num >= base)
		i = ft_numlen_base(num / base, base);
	return (++i);
}

void			ft_stdnum_base(signed long num, int base, const char *temp)
{
	if (num >= base)
	{
		ft_stdnum_base(num / base, base, temp);
		ft_stdnum_base(num % base, base, temp);
	}
	else
		ft_putchar(*(temp + num));
}

int				ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void			ft_field_def(const char *s, _obj *fld)
{
	fld->i++;
	while (ft_is_digit(*(s + fld->i)))
		fld->width = fld->width * 10 + (*(s + fld->i++) - 48);
	if (*(s + fld->i) == '.')
	{
		++fld->i;
		fld->if_precis = 1;
		while (ft_is_digit(*(s + fld->i)))
			fld->precis = fld->precis * 10 + (*(s + fld->i++) - 48);
	}
}

void			ft_putchar_len(int len, char c, _obj **out)
{
	while (len-- > 0)
	{
		ft_putchar(c);
		++(**out).output;
	}
}

void			ft_stds(_obj *proc)
{
	char	*s;

	++proc->i;
	s = va_arg(proc->list, char *);
	if (!s)
		s = "(null)";
	proc->len = ft_strlen(s);
	proc->len = (proc->precis < proc->len && proc->if_precis) ? proc->precis : proc->len;
	ft_putchar_len(proc->width - proc->len, ' ', &proc);
	ft_putstr_len(s, proc->len);
	proc->output += proc->len; 
}

void			ft_stdd(_obj *proc)
{
	signed long	num;

	++proc->i;
	num = (int)va_arg(proc->list, signed long);
	if (num < 0)
	{
		proc->neg = 1;
		num *= -1;
	}
	proc->len = ft_numlen_base(num, 10);
	if (!num && proc->if_precis)
		proc->len = 0;
	if (proc->if_precis && (proc->precis -= proc->len) > 0)
		proc->zero = proc->precis;
	proc->len += (proc->neg) ? 1 : 0;
	ft_putchar_len(proc->width - proc->zero - proc->len, ' ', &proc);
	if (proc->neg)
		ft_putchar('-');
	ft_putchar_len(proc->zero, '0', &proc);
	if (proc->if_precis && !num)
		return ;
	ft_stdnum_base(num, 10, "0123456789");
	proc->output += proc->len;
}

void			ft_stdx(_obj *proc)
{
	unsigned int	num;
	
	++proc->i;
	num = va_arg(proc->list, unsigned int);
	proc->len = ft_numlen_base(num, 16);
	if (proc->if_precis && (proc->precis -= proc->len) > 0)
		proc->zero = proc->precis;
	ft_putchar_len(proc->width - proc->zero - proc->len, ' ', &proc);
	ft_putchar_len(proc->zero, '0', &proc);
	ft_stdnum_base(num, 16, "0123456789abcdef");
	proc->output += proc->len;
}

int				ft_printf(const char *str, ...)
{
	_obj	hndl;

	ft_init_roll(&hndl);
	va_start(hndl.list, str);
	while (*(str + hndl.i))
	{
		ft_init_strct(&hndl);
		while (*(str + hndl.i) && *(str + hndl.i) != '%')
		{
			ft_putchar(*(str + hndl.i));
			++hndl.i;
			++hndl.output;
		}
		if (*(str + hndl.i))
		{
			ft_field_def(str, &hndl);
			if (*(str + hndl.i) == 'd')
				ft_stdd(&hndl);
			else if (*(str + hndl.i) == 'x')
				ft_stdx(&hndl);
			else if (*(str + hndl.i) == 's')
				ft_stds(&hndl);
		}
	}
	va_end(hndl.list);
	return (hndl.output);
}
