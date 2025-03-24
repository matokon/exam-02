/*

Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

*/


#include <stdio.h>

size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    
    while (s[i])
    {
       size_t j = 0;
       int counter = 0;
       while(accept[j])
       {
        if(s[i] == accept[j])
        {
            counter = 1;
            break;
        }
        j++;
       }
       if(counter != 1)
            return i;
        i++;
    }

    return i;
}

int main(void)
{
    const char str1[] = "abcd";
    const char str2[] = "abgd";

    size_t len = ft_strspn(str1, str2);
    printf("Length of initial segment matching: %zu\n", len);

    return 0;
}
