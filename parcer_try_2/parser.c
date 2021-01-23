#include "parser.h"

//typedef struct s_token
//{
//	int num;
//	char *text;
//} t_token;

int ft_pass(char *s)
{
	int i;
	
	i = 0;
	while(s[i])
	{
		if (s[i] == ' ')
			i++;
		else
			break;
	}
	return (i);
}

//int check_echo(char *s, int i)
//{
//	char *e;
//	int j;
//
//	j = 0;
//	e = "echo";
//	while(e[j])
//	{
//		if (s[i] == e[j])
//		{
//			i++;
//			j++;
//		}
//		else
//			return (0);
//	}
//	if (j == 3)
//		return (i);
//	return (0);
//}
//int spec_sym(char *s)
//{
//	const char *const	cmp[] = {
//	";",
//	"|",
//	"<",
//	"<<",
//	">",
//	">>",
//	"||",
//	"&&",
//	""
//};

//int main()
//{
//	int i;
//	char **words;
//	char *line;
//	char *test;
//
//	i = 0;
//	get_next_line(0, &line);
//	i = ft_pass(line);
//	test = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
//	while(line[i] != ' ')
//		*test++ = line[i++];
//	printf("%s", test);
//	return (0);
//}

int main()
{
	char *s1;
	char **s2;
	char c;
	
	s1 = "3xzv abcd xyz fmpg";
	c = ' ';
	s2 = ft_split(s1, c);
	while (*s2)
	{
		printf("%s\n", *s2);
		s2++;
	}
	return (0);
}
