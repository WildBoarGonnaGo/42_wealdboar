#include "parser.h"

typedef struct s_list
{
    char *word;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(char *word)
{
    t_list *new_elem;

    if (!(new_elem = (t_list *) malloc(sizeof(t_list))))
        return (NULL);
    new_elem->word = word;
    new_elem->next = NULL;
    return (new_elem);
}

void add_elem_end(char *word, t_list **head)
{
    t_list *new_lst;
    t_list *tmp;

    new_lst = ft_lstnew(word);
    if (!*head) {
        *head = new_lst;
        return ;
    }
    tmp = *head;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp->next = new_lst;
}

int main()
{
	char *s1;
	char **s2;
	t_list *list;

	get_next_line(0, &s1);
	//c = ' ';
	//s2 = ft_split(s1, c);
	s2 = create_words(s1);
	list  = NULL;
 	while (*s2)
    {
        add_elem_end(*s2, &list);
		s2++;
	}
	while (list)
    {
	    printf("%s\n", list -> word);
	    list = list -> next;
    }
	return (0);
}
