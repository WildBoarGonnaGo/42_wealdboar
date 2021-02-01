#include "parser.h"
//
int pass_spaces(char *s, int i)
{
    while(s[i] == ' ')
        i++;
    return (i);
}
//char single_quote(char *s, int i)
//{
//
//}
//
//char double_quote(char *s, int i)
//{
//
//}
//
//char **semicolon(char *s)
//{
//
//}

char **create_words(char *s)
{
    int i;
    int j;
    char **words;

    i = 0;
    j = 0;
    while(s[i])
    {
        i = pass_spaces(s, i);
        while (s[i] && (s[i] != ' '))
        {
            words[j] = malloc(sizeof(char) * 1);
            if ((ft_isspec(s[i])) == 0)
                *words[j] = ft_strjoinc(words[j], s[i++]);
         }
        j++;
    }
    return (words);
}