#include "../../include/libasm_bonus.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int 	info[3];
	t_list	*tool[3];
	void 	*buf;

	info[0] = ft_list_size(*begin_list);
	info[1] = -1;
	tool[0] = *begin_list;
	while (++info[1] < info[0])
	{
		info[2] = -1;
		tool[1] = tool[0];
		tool[2] = tool[0]->next;
		while (++info[2] < info[0] - 1)
		{
			if (cmp(tool[1]->data, tool[2]->data) > 0)
			{
				buf = tool[1]->data;
				tool[1]->data = tool[2]->data;
				tool[2]->data = buf;
			}
			tool[1] = tool[1]->next;
			tool[2] = tool[1]->next;
		}
	}
}
