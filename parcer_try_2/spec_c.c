#include <stdio.h>

int main()
{
    char c;

    scanf("%c", &c);
    if (c == '\'')
    {
        printf("kavychka epta");
        return (0);
    }
    if (c == ((char)48))
    {
        printf("otstoi");  // 0
        return (0);
    }
}