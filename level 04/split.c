#include <stdlib.h>
#include <stdio.h>

int word_counter(char *str)
{
    int counter = 0;
    int i = 0;
    while(str[i])
    {
        while(str[i] == ' ' || str[i] == '\t')
            i++;
        if(str[i])
        {
            counter++;
            while(str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
        }
    }
    
    return counter;
}


// char **ft_split(char *str)s
// {
// }


int main()
{
    printf("%d",word_counter("      "));
}