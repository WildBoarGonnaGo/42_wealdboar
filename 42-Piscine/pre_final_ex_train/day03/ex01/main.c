#include <stdio.h>
#include <stdlib.h>
void	ft_ultimate_ft(int *********nbr);

int main(void)
{
	int		a;
	int 	*ptr1;
	int		**ptr2;
	int		***ptr3;
	int		****ptr4;
	int		*****ptr5;
	int		******ptr6;
	int		*******ptr7;
	int		********ptr8;
	int		*********ptr9;

	a = 15;
	ptr1 = &a;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;

	printf("Number before changes: %d\n", a);
	ft_ultimate_ft(ptr9);
	printf("Number after changes: %d\n", a);
	return (0);
}
