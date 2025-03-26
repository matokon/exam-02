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
char *extract(char *str, int *c)
{
    char *extract1;
    int len = 0;
    int a = *c;
    int b = 0;
    while(str[a] == ' ')
    {
        a++;
    }
    *c = a;

    while(str[*c] != ' ' && str[*c])
    {
        (*c)++;
        len++;
    }

    extract1 = (char *)malloc(sizeof(char) * len + 1);
    if(!extract1)
        return NULL;

    while(len != 0)
    {
        extract1[b] = str[a];
        b++;
        a++;
        len--;
    }
    extract1[b] = '\0';


    return extract1;
}

char **ft_split(char *str)
{
    int a = 0;
    int index = 0;
    if(!str)
        return NULL;
    int words = word_counter(str);
    char **str_table = (char **)malloc(sizeof(char *) * (words + 1));
    if(!str_table)
        return NULL;
    while(a < words)
    {
        str_table[a] = extract(str, &index);
        if(!str_table[a])
        {
            while (a >= 0)
                free(str_table[a--]);
            free(str_table);
            return (NULL);
        }
        a++;
        str_table[a] = '\0';
    }
    return str_table;
}


int main()
{
	char *test = "sero sero seor soer ";
	char **a = ft_split(test);
	int j = 0; 
	while(j < 4)
	{
		printf("%s", a[j]);
		printf(" ");
		j++;
	}
	return 0;
}