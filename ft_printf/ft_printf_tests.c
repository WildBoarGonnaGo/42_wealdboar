#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/libft_expand.h"

int		ft_printf_base(char *strArg, ...)
{
	va_list	char_frwrd;
	int		count;
	int		unit;

	unit = 0;
	count = -1;
	va_start(char_frwrd, strArg);
	while (*(strArg + (++count)))
	{
		if (*(strArg + count) != '%')
			ft_putchar_fd(*(strArg + count), 1);
		else
		{
			++count;
			if ((unit = ft_printf_manager(strArg + count, char_frwrd)) < 0)
				return (-1);
			count += unit;
		}
	}
	va_end(char_frwrd);
	return (0);
}

int	main(void)
{
	void	*rage;

	rage = malloc(1);
	ft_printf_base("ft_000 | hello there, you lazy shmug %++-++11.4d %---+7d\n", -100, 2040);
	printf("tr_000 | hello there, you lazy shmug %++-++11.4d %---+7d\n", -100, 2040);
	ft_printf_base("ft_001 | hello there, you lazy shmug %++-++11d %---+7d\n", -100, 2040);
	printf("tr_001 | hello there, you lazy shmug %++-++11d %---+7d\n", -100, 2040);
	printf("%10s", "--= INTEGER VALUES WITH FORMATTING TESTS =--\n\n");
	ft_printf_base("ft_002 | ft_test_3: %u %d|\n", -100, 2040);
	printf("tr_002 | tr_test_4: %u %d|\n", -100, 2040);
	ft_printf_base("ft_003 | ft_test_3: %5u %d|\n", -100, 2040);
	printf("tr_003 | tr_test_4: %5u %d|\n", -100, 2040);
	ft_printf_base("ft_004 | ft_test_3: %22u %d|\n", -100, 2040);
	printf("tr_004 | tr_test_4: %22u %d|\n", -100, 2040);
	ft_printf_base("ft_005 | ft_test_3: %022u %i|\n", -100, 2040);
	printf("tr_005 | tr_test_4: %022u %i|\n", -100, 2040);
	ft_printf_base("ft_006 | ft_test_3: %-22u %i|\n", -100, 2040);
	printf("tr_006 | tr_test_4: %-22u %i|\n", -100, 2040);
	ft_printf_base("ft_007 | ft_test_3: %-----22u %7i|\n", -100, 2040);
	printf("tr_007 | tr_test_4: %-----22u %7i|\n", -100, 2040);
	ft_printf_base("ft_008 | ft_test_3: %-----22u %++--7i|\n", -100, 2040);
	printf("tr_008 | tr_test_4: %-----22u %++--7i|\n", -100, 2040);
	ft_printf_base("ft_008 | ft_test_3: %-----22u %++--*i|\n", -100, 7, 2040);
	printf("tr_008 | tr_test_4: %-----22u %++--*i|\n", -100, 7, 2040);
	ft_printf_base("ft_009 | ft_test_3: %-----22u %++--*.6i|\n", -100, 7, 2040);
	printf("tr_009 | tr_test_4: %-----22u %++--*.6i|\n", -100, 7, 2040);
	ft_printf_base("ft_009 | ft_test_3: %-----22u %++--*.*i|\n", -100, 10, 8, 2040);
	printf("tr_009 | tr_test_4: %-----22u %++--*.*i|\n", -100, 10, 8, 2040);
	ft_printf_base("ft_010 | ft_test_3: %-----22u %0*.*i|\n", -100, 10, 8, 2040);
	printf("tr_010 | tr_test_4: %-----22u %0*.*i|\n", -100, 10, 8, 2040);
	ft_printf_base("ft_010 | ft_test_3: %-----22u %0*i|\n", -100, 10, 2040);
	printf("tr_010 | tr_test_4: %-----22u %0*i|\n", -100, 10, 2040);
	ft_printf_base("ft_011 | ft_test_3: %-----22u %++0*i|\n", -100, 10, 2040);
	printf("tr_011 | tr_test_4: %-----22u %++0*i|\n", -100, 10, 2040);
	ft_printf_base("ft_012 | ft_test_3: %-----22u %++0.*i|\n", -100, 10, 2040);
	printf("tr_012 | tr_test_4: %-----22u %++0.*i|\n", -100, 10, 2040);
	ft_printf_base("ft_013 | ft_test_3: %-----22u %++0*.*i|\n", -10000, 10, 7, 2040);
	printf("tr_013 | tr_test_4: %-----22u %++0*.*i|\n", -10000, 10, 7, 2040);
	ft_printf_base("ft_013 | ft_test_3: %-----22u %++0*.*i|\n", -10000, 10, 7, 2040);
	printf("tr_013 | tr_test_4: %-----22u %++0*.*i|\n", -10000, 10, 7, 2040);
	ft_printf_base("ft_014 | ft_test_3: %-----22u %++*.*i|\n", 10000, 10, 7, -2040);
	printf("tr_014 | tr_test_4: %-----22u %++*.*i|\n", 10000, 10, 7, -2040);
	ft_printf_base("ft_015 | ft_test_3: %-----22u %++*d|\n", 10000, 10, -2040);
	printf("tr_015 | tr_test_4: %-----22u %++*d|\n", 10000, 10, -2040);
	ft_printf_base("ft_016 | ft_test_3: %-----22u %++--*d|\n", 10000, 10, -2040);
	printf("tr_016 | tr_test_4: %-----22u %++--*d|\n", 10000, 10, -2040);
	ft_printf_base("ft_017 | ft_test_3: %-----22.7u %++0*.7d|\n", 10000, 10, -2040);
	printf("tr_017 | tr_test_4: %-----22.7u %++0*.7d|\n", 10000, 10, -2040);
	ft_printf_base("ft_018 | ft_test_3: %-----22.22u %++0*.7d|\n", 10000, 10, -2040);
	printf("tr_018 | tr_test_4: %-----22.22u %++0*.7d|\n", 10000, 10, -2040);
	ft_printf_base("ft_019 | ft_test_3: %-----22.48u %++0*.7d|\n", 10000, 10, -2040);
	printf("tr_019 | tr_test_4: %-----22.48u %++0*.7d|\n", 10000, 10, -2040);

	ft_printf_base("%10s", "\n--= STRING AND CHAR VALUES WITH FORMATTING TESTS =--\n\n");
	ft_printf_base("ft_str_test_001: %s %c|\n", "Hello, World!", 65);
	printf("tr_str_test_001: %s %c|\n", "Hello, World!", 65);
	ft_printf_base("ft_str_test_002: %12s %c|\n", "Hello, World!", 65);
	printf("tr_str_test_002: %12s %c|\n", "Hello, World!", 65);
	ft_printf_base("ft_str_test_003: %24s %c|\n", "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_003: %24s %c|\n", "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_004: %-24.s %c|\n", "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_004: %-24.s %c|\n", "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_005: %-24.10s %c|\n", "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_005: %-24.10s %c|\n", "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_006: %-24.*s %c|\n", 70, "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_006: %-24.*s %c|\n", 70, "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_007: %-24.*s %c|\n", 22, "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_007: %-24.*s %c|\n", 22, "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_008: %-*.*s %c|\n", 24, 23, "Omae wa mou shindeiru!", 65);
	printf("tr_str_test_008: %-*.*s %c|\n", 24, 23, "Omae wa mou shindeiru!", 65);
	ft_printf_base("ft_str_test_009: %-*.*s %10c|\n", 24, 23, "Omae wa mou shindeiru!", 78);
	printf("tr_str_test_009: %-*.*s %10c|\n", 24, 23, "Omae wa mou shindeiru!", 78);
	ft_printf_base("ft_str_test_010: %-*.*s %-10c|\n", 24, 23, "Omae wa mou shindeiru!", 78);
	printf("tr_str_test_010: %-*.*s %-10c|\n", 24, 23, "Omae wa mou shindeiru!", 78);
	ft_printf_base("ft_str_test_011: %-*.*s %-*c|\n", 24, 23, "Omae wa mou shindeiru!", 13, 78);
	printf("tr_str_test_011: %-*.*s %-*c|\n", 24, 23, "Omae wa mou shindeiru!", 13, 78);
	ft_printf_base("ft_str_test_011: %-*.*s %-*.c|\n", 24, 23, "Omae wa mou shindeiru!", 13, 78);
	printf("tr_str_test_011: %-*.*s %-*.c|\n", 24, 23, "Omae wa mou shindeiru!", 13, 78);
	
	ft_printf_base("%10s", "\n--= HEXADECIMAL FORMATS =--\n\n");
	ft_printf_base("ft_hex_test_001 | %p|\n", rage);
	printf("tr_hex_test_001 | %p|\n", rage);
	ft_printf_base("ft_hex_test_002 | %14p|\n", rage);
	printf("tr_hex_test_002 | %14p|\n", rage);
	ft_printf_base("ft_hex_test_003 | %-14p|\n", rage);
	printf("tr_hex_test_003 | %-14p|\n", rage);
	ft_printf_base("ft_hex_test_004 | %-14p|\n", NULL);
	printf("tr_hex_test_004 | %-14p|\n", NULL);
	ft_printf_base("ft_hex_test_005 | %-14.p|\n", rage);
	printf("tr_hex_test_005 | %-14.p|\n", rage);
	ft_printf_base("ft_hex_test_006 | %x|\n", (int)rage);
	printf("tr_hex_test_006 | %x|\n", (int)rage);
	ft_printf_base("ft_hex_test_007 | %15x|\n", (int)rage);
	printf("tr_hex_test_007 | %15x|\n", (int)rage);
	ft_printf_base("ft_hex_test_008 | %-15x|\n", (int)rage);
	printf("tr_hex_test_008 | %-15x|\n", (int)rage);
	ft_printf_base("ft_hex_test_009 | %-23.x|\n", (int)rage);
	printf("tr_hex_test_009 | %-23.x|\n", (int)rage);
	ft_printf_base("ft_hex_test_009 | %23.x|\n", (int)rage);
	printf("tr_hex_test_009 | %23.x|\n", (int)rage);
	ft_printf_base("ft_hex_test_010 | %023.x|\n", (int)rage);
	printf("tr_hex_test_010 | %023.x|\n", (int)rage);
	ft_printf_base("ft_hex_test_011 | %023.26x|\n", (int)rage);
	printf("tr_hex_test_011 | %023.26x|\n", (int)rage);
	ft_printf_base("ft_hex_test_012 | %23.23x|\n", (int)rage);
	printf("tr_hex_test_012 | %23.23x|\n", (int)rage);
	ft_printf_base("ft_hex_test_013 | %23.21x|\n", (int)rage);
	printf("tr_hex_test_013 | %23.21x|\n", (int)rage);
	ft_printf_base("ft_hex_test_014 | %23.4x|\n", (int)rage);
	printf("tr_hex_test_014 | %23.4x|\n", (int)rage);
	ft_printf_base("ft_hex_test_015 | %-23.21x|\n", (int)rage);
	printf("tr_hex_test_015 | %-23.21x|\n", (int)rage);
	ft_printf_base("ft_hex_test_016 | %-23.4x|\n", (int)rage);
	printf("tr_hex_test_016 | %-23.4x|\n", (int)rage);
	ft_printf_base("ft_hex_test_016 | %-5.4x|\n", (int)rage);
	printf("tr_hex_test_016 | %-5.4x|\n", (int)rage);
	ft_printf_base("ft_hex_test_017 | %-5.4x|\n", -1500);
	printf("tr_hex_test_017 | %-5.4x|\n", -1500);
	ft_printf_base("ft_hex_test_018 | %-5.4x|\n", 0);
	printf("tr_hex_test_018 | %-5.4x|\n", 0);
	ft_printf_base("ft_hex_test_019 | %-.x|\n", 1500);
	printf("tr_hex_test_019 | %-.x|\n", 1500);
	ft_printf_base("tr_hex_test_020 | %X|\n", (int)rage);
	printf("tr_hex_test_020 | %X|\n", (int)rage);
	ft_printf_base("ft_hex_test_021 | %15X|\n", (int)rage);
	printf("tr_hex_test_021 | %15X|\n", (int)rage);
	ft_printf_base("ft_hex_test_022 | %-15X|\n", (int)rage);
	printf("tr_hex_test_022 | %-15X|\n", (int)rage);
	ft_printf_base("ft_hex_test_023 | %-23.X|\n", (int)rage);
	printf("tr_hex_test_023 | %-23.X|\n", (int)rage);
	ft_printf_base("ft_hex_test_024 | %23.X|\n", (int)rage);
	printf("tr_hex_test_024 | %23.X|\n", (int)rage);
	ft_printf_base("ft_hex_test_025 | %023.X|\n", (int)rage);
	printf("tr_hex_test_025 | %023.X|\n", (int)rage);
	ft_printf_base("ft_hex_test_026 | %023.26X|\n", (int)rage);
	printf("tr_hex_test_026 | %023.26X|\n", (int)rage);
	ft_printf_base("ft_hex_test_027 | %23.23X|\n", (int)rage);
	printf("tr_hex_test_027 | %23.23X|\n", (int)rage);
	ft_printf_base("ft_hex_test_028 | %23.21X|\n", (int)rage);
	printf("tr_hex_test_028 | %23.21X|\n", (int)rage);
	ft_printf_base("ft_hex_test_029 | %23.4X|\n", (int)rage);
	printf("tr_hex_test_029 | %23.4X|\n", (int)rage);
	ft_printf_base("ft_hex_test_030 | %-23.21X|\n", (int)rage);
	printf("tr_hex_test_030 | %-23.21X|\n", (int)rage);
	ft_printf_base("ft_hex_test_031 | %-23.4X|\n", (int)rage);
	printf("tr_hex_test_031 | %-23.4X|\n", (int)rage);
	ft_printf_base("ft_hex_test_032 | %-5.4X|\n", (int)rage);
	printf("tr_hex_test_032 | %-5.4X|\n", (int)rage);
	ft_printf_base("ft_hex_test_033 | %-5.4X|\n", -1500);
	printf("tr_hex_test_033 | %-5.4X|\n", -1500);
	ft_printf_base("ft_hex_test_034 | %-5.4X|\n", 0);
	printf("tr_hex_test_034 | %-5.4X|\n", 0);
	ft_printf_base("ft_hex_test_035 | %-.X|\n", 1500);
	printf("tr_hex_test_035 | %-.X|\n", 1500);


	//printf("tr_002 | tr_test_3: %+u %d\n", -100, 2040); 

	//printf("tr_002 | tr_test_3: %+u %d\n", -100, 2040); 
	// '+' character and %u convertion are incopatible
	
	//ft_printf_base("Hey hey people, %c\n", 'A');
	//printf("Hey hey people, %c\n", 'A');
	ft_mem_reset(&rage);
	return (0);
}
