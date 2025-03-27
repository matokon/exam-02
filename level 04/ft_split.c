#include <stdlib.h>
#include <stdio.h>

int words_counter(char *str)
{
    int words = 0;
    int i = 0;
    while(str[i])
    {
        while(str[i] == ' ' || str[i] == '\t')
        {
            i++;
        }
        if(str[i] != ' ' && str[i] != '\t' && str[i])
        {
            words++;
            while(str[i] != ' ' && str[i] != '\t' && str[i])
                i++;
        }
    }
    return words;
}
 
char *extract(char *str, int *c)
{
    int a = *c;
    int b = 0;
    int len = 0;
    char *extract1;
    while (str[a] == ' ')
		a++;
	*c = a;
    while(str[*c] != ' ' && str[*c])
    {
        (*c)++;
        len++;
    }
        
    extract1 = (char *)malloc(sizeof(char *) * (len + 1));
    if(!extract1)
        return NULL;
    while(len--)
    {
        extract1[b] = str[a];
        a++;
        b++;
    }
    extract1[b] = '\0';
    return extract1;
}


char    **ft_split(char *str)
{
    int words = 0;
    int index = 0;
    int a = 0;
    char **str_table;
    if(!str)
        return NULL;
    words = words_counter(str);
    str_table = (char **)malloc(sizeof(char *) * (words + 1));
    if(!str_table)
        return NULL;
    while(a < words)
    {
        str_table[a] = extract(str, &index);
        if(!str_table[a])
        {
            while(a >= 0)
                free(str_table[a--]);
            free(str_table);
            return NULL;
        }
        a++;
    }
    str_table[a] = "\0";
    return str_table;
}

int main()
{
    int i = 0;
    char *str = "     word1 word2 word3 word4     ";
    char **a = ft_split(str);
    while(a[i])
    {
        printf("%s", a[i]);
        i++;
    }
}
