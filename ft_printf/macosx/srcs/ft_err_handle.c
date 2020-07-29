#include "../include/ft_printf_out.h"

int	ft_err_handle(const char *src)
{
	int	pos;

	pos = 0;
	while (*(src + pos))
	{
		if (*(src + pos) != '%')
			++pos;
		else
		{
			++pos;
			while (ft_strchr("-+0", *(src + pos)) && *(src + pos))
				++pos;
			while (ft_strchr("1234567890*", *(src + pos)) && *(src + pos))
				++pos;
			if (*(src + pos) == '.')
			{
				++pos;	
				while (ft_strchr("1234567890*", *(src + pos)) && *(src + pos))
					++pos;
			}
			if (!ft_strchr("cspdiuxX%", *(src + pos)) || !*(src + pos))
				return (0);
			++pos;
		}
	}
	return (1);			
}
