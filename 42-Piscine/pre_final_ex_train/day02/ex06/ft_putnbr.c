# define	INT_MIN	-2147483647
# define	INT_MAX 2147483647

void		ft_putchar(char c);

void		ft_putnbr(int nb)
{
	int	div;

	div = 1000000000;
	if (nb < INT_MIN || nb > INT_MAX)
		return ;
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= (-1);
	}
	while (nb / div == 0)
		div /= 10; 
	while (div >= 1)
	{
		ft_putchar(nb / div + 48);
		nb -= nb / div * div;
		div /= 10;
	}
}
