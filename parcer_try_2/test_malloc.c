#include <stdlib.h>
#include <stdio.h>

int main()
{
    char **s;
    char *x = "testing allocating memory lol";
    int i = 0;
    int j = 0;

    s = (char**)malloc(sizeof(char*) * (4));
    while (x[i])
    {
        s[j] = (char*)malloc(3);
        while(x[i] && (x[i] != ' '))
        {
            s[j][0] = x[i];
            s[j][1] = '\0';  //MEMREALLOC
            i++;
        }
        i++;
        j++;
    }
    while (*s)
    {
        printf("%s\n", *s);
        s++;
    }
    return 0;
}