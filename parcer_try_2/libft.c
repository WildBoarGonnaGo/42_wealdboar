#include "parser.h"

int	ft_isspec(char c)
{
    if ((c == ((char)36)) || ((c == '\'')) || (c == (char)92) || (c == (char)34))
        return (1);
    else
        return (0);
}

//int ft_strlen(char *s)
//{
//    int i;
//
//    i = 0;
//    while (s[i])
//        i++;
//    return (i);
//}

void	*memrealloc(void *mem, int oldsize, int addbyte)
{
    void	*res;
    int		indx;
    void	*mem_to_purge;

    indx = -1;
    oldsize += (addbyte < 0) * addbyte;
    mem_to_purge = mem;
    res = malloc(oldsize + (addbyte > 0) * addbyte);
    while (++indx < oldsize && mem)
        *(char *)(res + indx) = *(char *)(mem + indx);
    while (indx < oldsize + addbyte)
        *(char *)(res + indx++) = 0;
    if (mem_to_purge)
        free(mem_to_purge);
    return (res);
}


char *addchar(char *src, char c)
{
    int i;
    int len;
    char *res;

    i = -1;
    len = 0;
    if (!src)
        return (0);
    len = ft_strlen(src);
    res = (char *)malloc(len + 2);
    while (src[++i])
        res[i] = src[i];
    res[i++] = c;
    res[i] = 0;
    return (res);
}

char *ft_strjoinc(char *s, char c)
{
    int i;
    int j;
    char *out;

    i = 0;
    j = 0;
    out = malloc(sizeof(char) * (ft_strlen(s) +2));
    while (s[i])
        out[j++] = s[i++];
    out[j++] = c;
    out[j] = '\0';
    free(s);
    return (out);
}

int pass_spaces(char *s, int i)
{
    while(s[i] == ' ')
        i++;
    return (i);
}

int main()
{
    char **words;
    char *clean;
    char *s;
    int i;
    int j;
    int x;

    i = 0;
    j = 0;
    get_next_line(0, &s);
    words = (char **)malloc(sizeof(char *) * 1);
    while(s[i])
    {
        words = (char **)malloc(sizeof(char *) * 1);
        i = pass_spaces(s, i);
        x = 0;
        words[j] = (char *)malloc(1);
        words[j][0] = 0;
        while (s[i] && (s[i] != ' '))
        {
            clean = words[j];
            if ((ft_isspec(s[i])) == 0)
            {
                words[j] = addchar(words[j], s[i++]);
                free(clean);
            }
        }
        j++;
    }
    while (*words)
    {
        printf("%s\n", *words);
        words++;
    }
    return (0);
}

