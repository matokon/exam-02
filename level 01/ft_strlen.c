/* 

Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

*/
#include <stdio.h>

int	ft_strlen(char *str)
{
    int length;
    length = 0;
    while(str[length])
    {
        length++;
    }
    return length;
}
void main(){
    printf("%d",ft_strlen("12345"));
}