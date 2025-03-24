/*

Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/

char    *ft_strrev(char *str)
{
    char tmp;
    int i;
    i = 0;
    while(str[i])
    {
        i++;
    }
    i--;
    int j;
    j = 0;
    while(i > j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return str;
}
#include <stdio.h>

int main()
{
    char str[] = "hello"; 
    printf("%s",ft_strrev(str));
    return 0;
}