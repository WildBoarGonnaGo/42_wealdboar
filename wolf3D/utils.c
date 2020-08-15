/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:35:19 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/14 05:32:21 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_memreset(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

int		ft_strlen(char *str)
{
	int	pos;

	if (!str)
		return (0);
	pos = -1;
	while (*(str + ++pos))
		;
	return (pos);
}

void	displ_bits(int val)
{
	static int count;

	if (val)
	{
		++count;
		displ_bits(val >> 1);
		if (!(count % 8))
			putchar(' ');
		--count;
		printf("%d", val & 1);
	}
}

char	*ft_strjoin(char *src, char *dst)
{
	int 	size;
	char	*res;
	int		pos[2];

	pos[0] = -1;
	pos[1] = -1;
	size = 0;
	if (!src)
		return (NULL);
	if (!dst)
		return (src);
	size += ft_strlen(src);
	size += ft_strlen(dst);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	while (*(src + ++pos[0]))
		*(res + pos[0]) = *(src + pos[0]);
	while (*(dst + ++pos[1]))
		*(res + pos[0]++) = *(dst + pos[1]);
	*(res + pos[0]) = 0;
	return (res);
}

char	*ft_strdup(char *str)
{
	char 	*res;
	int		size;
	int		pos;

	pos = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = *(str + pos);
	*(res + pos) = 0;
	return (res);
}

int		get_bitnum(int a)
{
	int	size;

	size = -1;
	if (a)
		size = get_bitnum(a >> 1);
	return (++size);
}

char	*ft_charjoin(char *str, char c)
{
	int		size;
	char	*res;
	int		pos;

	pos = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 2)))
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = *(str + pos);
	*(res + pos++) = c;
	*(res + pos) = 0;
	return (res);
}

char		*gethex_impl(unsigned int a)
{
	int		info[3];
	char	*res;
	int		size;

	info[0] = 1;
	info[1] = 0;
	size = get_bitnum(a);
	info[2] = ((size % 4) > 0);
	size = (info[2]) ? size / 4 + 1 : size / 4;
	if (!(res = (char *)malloc(size + 3)))
		return (NULL);
	*(res + size) = 0;
	while (a)
	{
		if ((a & 1))
			info[1] += info[0];
		if (!(info[0] % 8))
		{
			*(res + --size) = "0123456789ABCDEF"[info[1]];
			info[0] = 1;
			info[1] = 0;
			a >>= 1;
			continue ;
		}
		info[0] *= 2;
		a >>= 1;
	}
	if (info[2])
		*(res + --size) = "0123456789ABCDEF"[info[1]];
	return (res);
}

int		ft_isspace(char c)
{
	return ((c >= 9 && c <= 13));
}

int		ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

char	ft_tolower(char c)
{
		return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

char	*ft_strchr(char *str, char c)
{
	int	pos;

	pos = -1;
	if (!str)
		return (NULL);
	while (*(str + ++pos))
		if (*(str + pos) == c)
			return (str + pos);
	return (NULL);
}

char	*ft_str_tolower(char *str)
{
	char	*res;
	int		size;
	int		pos;

	pos = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = ft_tolower(*(str + pos));
	*(res + pos) = 0;
	return (res);
}

unsigned int	ft_atou_base(char *num, int base)
{
	unsigned int		res;
	int					pos;
	char				*mem_info[2];
	int					dif;

	res = 0;
	pos = 0;
	mem_info[0] = ft_str_tolower(num);
	mem_info[1] = mem_info[0];
	while (ft_isspace(*(mem_info[0] + pos)))
		++pos;
	while (ft_strchr("+", *(mem_info[0] + pos)))
		++pos;
	if (*(mem_info[0] + pos) == '0' && *(mem_info[0] + pos + 1) == 'x')
		pos += 2;
	while (ft_strchr("0123456789abcdef", *(mem_info[0] + pos)) && *(mem_info[0] + pos))
	{
		res *= base;
		dif = (ft_isdigit(*(mem_info[0] + pos))) ? '0' : 'W';
		res += (*(mem_info[0] + pos) - dif) % base;
		++pos;
	}
	ft_memreset((void **)&mem_info[1]);
	return (res);
}

/*int		main(void)
{
	int		a = 0xFF;
	char	*hex;

	printf("bits implementation of \'a\': ");
	displ_bits(a);
	putchar('\n');
	hex = gethex_impl((unsigned int)a);
	printf("decimal value of \'a\': %d\n", a);
	printf("hex implementation of \'a\': %s\n", hex);
	printf("true hex implementation of \'a\': %x\n", a);
	return (0);
}*/
