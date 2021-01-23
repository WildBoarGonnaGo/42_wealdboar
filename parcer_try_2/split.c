#include "parser.h"

static size_t	ft_nwords(char const *s, char c)
{
    size_t		j;
    size_t		i;

    j = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
            j++;
        i++;
    }
    return (j);
}

static size_t	ft_len(char const *s, char c)
{
    size_t		l1;
    size_t		i;

    l1 = 0;
    i = 0;
    while (s[i] == c)
        i++;
    while (s[i] != '\0' && s[i] != c)
    {
        l1++;
        i++;
    }
    return (l1);
}

static void		*arr_free(char **arr)
{
    size_t		i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    return (NULL);
}

char			**ft_split(char const *s, char c)
{
    char		**arr;
    size_t		i;
    size_t		j;
    size_t		k;

    i = 0;
    k = 0;
    if (s == NULL || !(arr = (char**)malloc(sizeof(char*) *
                                            (ft_nwords(s, c) + 1))))
        return (NULL);
    while (i < ft_nwords(s, c))
    {
        if (!(arr[i] = (char*)malloc(sizeof(char) * (ft_len(s + k, c) + 1))))
            return (arr_free(arr));
        j = 0;
        while (s[k] == c)
            k++;
        while (s[k] != '\0' && s[k] != c)
            arr[i][j++] = s[k++];
        arr[i][j] = '\0';
        i++;
    }
    arr[i] = NULL;
    return (arr);
}