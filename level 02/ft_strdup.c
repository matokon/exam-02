/*

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
    char *duplicate;
    int len;
    len = 0;
    while(src[len])
    {
        len++;
    }
    duplicate = (char*)malloc(sizeof(char)*(len+1));
    int i;
    i = 0;
    while(src[i])
    {
        duplicate[i] = src[i];
        i++;
    }
    duplicate[i] = '\0';
    return duplicate;
}
