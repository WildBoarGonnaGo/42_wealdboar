#include "./include/libasm_bonus.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)());

t_list			*ft_create_elem(void *data)
{
	t_list		*rage;
	
	if (!(rage = (t_list *)malloc(sizeof(t_list))))
		return (null);
	rage->data = data;
	rage->next = null;
	return (rage);
}

void			ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*rage;
	t_list	*loop;

	loop = *begin_list;
	rage = (t_list *)malloc(sizeof(t_list));
	rage->data = data;
	rage->next = null;
	while (loop->next)
		loop = loop->next;
	loop->next = rage;
}

int				main(void)
{
	int 	i;
	int		len;
	char	*str;
	char	*src = "Tsugi wa Jotaro! Kisama da";
	char	*dst;
	char	*hell = "Suda podoshel";
	char	*yell = "Da ty ohuel";
	char	*sseth = "Hey hey people Sseth here";
	char	*sseth1 = "to put it simply, they are fucking wrong!";
	char	*sseth2 = "17 years old bitch";
	char	*sdup;
	ssize_t	errs[2];
	t_list	*ur_mom;
	t_list	*loop;

	ur_mom = NULL;
	str = (char *)malloc(ft_strlen(src));
	len = ft_strlen(src);
	printf("Length of string: %d\n", len);
	dst = ft_strcpy(str, src);
	printf("Copy of string: %s\n", dst);
	len = ft_strcmp(hell, yell);
	printf("Diffrence between two strings: %d\n", len);
	printf("Diffrence between two strings with two strcmp: %d\n", strcmp(hell, yell));
	sdup = ft_strdup(src);
	printf("copied string: %s\n", sdup);
	errs[0] = write(-1, "Hello\n", 6);
	errs[1] = ft_write(-1, "Hello\n", 6);
	printf("Error code of original write (errs[0]): %zd\n", errs[0]);
	printf("Error code of user\'s write (errs[1]): %zd\n", errs[1]);
	printf("Integer value of 'o1232': %d\n", ft_atoi_base("1232", "01234567"));
	printf("Size of \'ur_mom\' list: %d\n", ft_list_size(ur_mom));
	ur_mom = ft_create_elem(hell);
	printf("Size of \'ur_mom\' list: %d\n", ft_list_size(ur_mom));
	ft_list_push_front(&ur_mom, yell);
	printf("Size pf \'ur_mom\' list: %d\n", ft_list_size(ur_mom));
	ft_list_push_back(&ur_mom, sseth1);
	ft_list_push_back(&ur_mom, sseth);
	ft_list_push_back(&ur_mom, sseth2);
	len = ft_list_size(ur_mom);
	i = -1;
	loop = ur_mom;
	printf("List before sort:\n");
	while (++i < len)
	{
		printf("ur_mom[%d]:\n", i);
		printf("address: 0x%x\n", (int)loop);
		printf("data: %s\n", loop->data);
		loop = loop->next;
	}
	loop = ur_mom;
	i = -1;
	ft_list_sort(&ur_mom, ft_strcmp);
	printf("List after sort:\n");
	while (++i < len)
	{
		printf("ur_mom[%d]:\n", i);
		printf("address: 0x%x\n", (int)loop);
		printf("data: %s\n", loop->data);
		loop = loop->next;
	}
	free(ur_mom->next);
	free(ur_mom);
	free(sdup);
	free(str);	
	return(0);
}
