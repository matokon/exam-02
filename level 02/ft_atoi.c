/*

Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

*/
#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i;
    i = 0;
    int sign;
    sign = 1;
    int result;
    result = 0;
    while(str[i] >= 9 && str[i] <= 13 || str[i] == 32)
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = sign * (-1);
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    } 
    return result * sign;
}
int main()
{
    printf("%d\n", ft_atoi("123"));
    printf("%d\n", ft_atoi("   -42"));
    printf("%d\n", ft_atoi(" +77 "));
    printf("%d\n", ft_atoi("  0045abc"));
    return 0;
}