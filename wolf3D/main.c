/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:06:00 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/10 20:33:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		return (0)'
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

char	*gethex_impl(int a)
{
	int		info[3];
	char	*res;
	char 	templ[15];
	char	*mem_topurge;

	info[0] = 1;
	info[1] = 0;
	templ = "0123456789ABCDEF";
	res = ft_strdup("0x");
	while (a)
	{
		if ((a & 1))
			info[1] += info[0];
		if (!(info[0] % 8))
		{
			mem_topurge = res;
			res = ft_charjoin(res, templ[info[1]]);
			ft_memreset((void **)mem_topurge);
			info[0] = 1;
			info[1] = 0;
		}
		info[0] *= 2;
		a >>= 1;
	}
	return (res);
}

int		main(void)
{
	int	a = 0xFF;

	//a <<= 16;
	printf("bits implementation of \'a\': ");
	displ_bits(a);
	putchar('\n');
	printf("decimal value of \'a\': %d\n", a);
	return (0);
}
