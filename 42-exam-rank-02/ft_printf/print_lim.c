#include <stdio.h>
#include <limits.h>

typedef struct	nums
{
	int a;
	int	b;
}				coord;

void	swap(int *a, int *b)
{
	int	_swap;

	_swap = *a;
	*a = *b;
	*b = _swap;
}

int		main(void)
{
	coord	_obj;

	printf("a = ");
	scanf("%d", &_obj.a);
	printf("b = ");
	scanf("%d", &_obj.b);
	printf("a = %d, b = %d\n", _obj.a, _obj.b);
	swap(&_obj.a, &_obj.b);
	printf("a = %d, b = %d\n", _obj.a, _obj.b);
	return (0);
}
