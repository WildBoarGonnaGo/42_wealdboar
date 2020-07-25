#include <stdio.h>
#include <stdlib.h>
#include "../include/libft_expand.h"

int		ft_get_size_base(unsigned int num, int base)
{
	int	size;

	size = 0;
	while ((num /= base) > 0)
		++size;
	return (++size);
}

/*int		ft_get_size_base(unsigned int num, int base)
{
	int	size;

	size = 0;
	while ((num /= base) > 0)
		++size;
	return (++size);
}*/

char	remind_to_base(int val_to_write)
{
	if (val_to_write >= 0 && val_to_write < 10)
		return (val_to_write + '0');
	else
		return (val_to_write + 'a' - 10);
}

char	*ft_itoa_base(unsigned long long num, int base)
{
	char 	*result;
	int		func_info[3];

	func_info[1] = 1;
	if (!num)
		return (ft_strdup("0"));
	func_info[0] = ft_get_size_base((unsigned long long)num, base);
	if (!(result = (char *)malloc(func_info[0] + 1)))
		return (NULL);
	*(result + func_info[0]) = 0;
	num *= func_info[1];
	while (func_info[0]-- > 0)
	{
		func_info[2] = num % base;
		num /= base;
		if (func_info[1] < 0 && !func_info[0])
			*(result + func_info[0]) = '-';
		else
			*(result + func_info[0]) = remind_to_base(func_info[2]);
	}
	return (result);
}
