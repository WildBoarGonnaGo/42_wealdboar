#include "./include/ft_printf_out.h"
#include <stdio.h>

int	main(void)
{
	int result;

	result = 0;
	result = ft_printf("%%|\n");
	ft_printf("result = %d\n", result);
	result = printf("%%|\n");
	printf("result = %d\n", result);
	result = ft_printf("%0%|\n");
	ft_printf("result = %d\n", result);
	result = printf("%%|\n");
	printf("result = %d\n", result);
	result = ft_printf("%5%|\n");
	ft_printf("result = %d\n", result);
	result = printf("    %%|\n");
	printf("result = %d\n", result);
	result = ft_printf("%-5%|\n");
	ft_printf("result = %d\n", result);
	result = printf("%%    |\n");
	printf("result = %d\n", result);
	result = ft_printf("%05%|\n");
	ft_printf("result = %d\n", result);
	result = printf("0000%%|\n");
	printf("result = %d\n", result);
	result = ft_printf("%-05%|\n");
	ft_printf("result = %d\n", result);
	result = printf("%%    |\n");
	printf("result = %d\n", result);
	printf("%05d");
}
