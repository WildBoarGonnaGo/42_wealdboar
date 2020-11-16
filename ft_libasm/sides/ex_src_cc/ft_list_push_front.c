void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return ;
	node->data = data;
	node->next = *begin_list;
	*begin_list = node;
}
