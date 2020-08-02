/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day10_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:46:02 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 15:07:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char*));
int		ft_count_if(char **tab, int	(*f)(char*));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));

void	ft_power(int a)
{
	printf("%d ", a*a);
}

int		ft_if_only_alpha(char *s1)
{
	if (*s1 == ' ')
		return (ft_if_only_alpha(s1 + 1));	
	if (*s1 == '\0')
		return (1);
	if (*s1 != '\0' && ((*s1 >= 'A' && *s1 <= 'Z')
				|| (*s1 >= 'a' && *s1 <= 'z')))
		return (ft_if_only_alpha(s1 + 1));
	else
		return (0);
}

void	(ft_printnum(int a))
{
	printf("%d ", a);
}

int		ft_fn(int num)
{
	if (num < 0)
		return (0);
	if (num == 0)
		return (1);
	else
		return (num * ft_fn(num - 1));
}

int ft_num_diff(a, b)
{
	return (a - b);
}

int		main(void)
{
	int		*arr;
	int		len;
	int		index;
	char	**my_arr;
	int		arr1[3] = {};

	my_arr = (char**)malloc(sizeof(char*) * 3);
	my_arr[0] = (char*)malloc(sizeof(char) * 40);
	my_arr[1] = (char*)malloc(sizeof(char) * 40);
	my_arr[0] = "abcdegh";
	my_arr[1] = "Tsugi wa Jotaro Kisama da";
	*my_arr[2] = 0; 

	index = -1;
	len = 8;
	arr = (int*)malloc(sizeof(int) * len);
	while (++index < len)
		arr[index] = index + 1;
	ft_foreach(arr, len, &ft_power);
	free(arr);
	printf("\n");
	len = 6;
	index = -1;
	arr = (int*)malloc(sizeof(int) * len);
	while (++index < len)
		arr[index] = index;
	arr = ft_map(arr, len, &ft_fn);
	ft_foreach(arr, len, &ft_printnum);
	printf("\nsize of string: %lu", sizeof(my_arr[0]));
	printf("\nsize of strign: %lu", sizeof(my_arr[1]));
	printf("\nThe result of ft_any's: %d", ft_any(my_arr, ft_if_only_alpha));
	printf("\nThe length of valid string: %d\n", ft_count_if(my_arr, 
				ft_if_only_alpha));
	printf("\nIf array is sorted yes(1) or no(0) -> %d\n", ft_is_sort(arr1,
			0, ft_num_diff));
	return (0);
}
