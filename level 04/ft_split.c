/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:00:20 by e                 #+#    #+#             */
/*   Updated: 2025/03/26 15:16:27 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_word(const char *s)
{
	int count = 0;
	int i = 0;

	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				i++;
		}
	}
	return (count);
}

char *extract(char *str, int *c)
{
	int a = *c;
	char *extract1;
	int len = 0;
	int b = 0;
	while (str[a] == ' ')
		a++;
	*c = a;
	while (str[*c] != ' ' && str[*c])
	{
		(*c)++;
		len++;
	}
	extract1 = (char *)malloc(sizeof(char *) * (len + 1));
	if(!extract1)
		return NULL;
	while (len--)
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
	if(!str)
		return NULL;
	int a = 0;
	int index = 0;
	int words = count_word(str);
	char **strings;
	strings = (char **)malloc(sizeof(char*) * (words + 1));
	if(!strings)
		return NULL;
	while (a < words)
	{
		strings[a] = extract(str, &index);
		if (!strings[a])
        {
            while (a >= 0)
                free(strings[a--]);
            free(strings);
            return (NULL);
        }
		a++;
	}
	strings[a] = "\0";
	return strings;
}

int main()
{
	char *test = "sero sero seor soer ";
	char **a = ft_split(test);
	int j = 0; 
	while(j < 5)
	{
		printf("%s", a[j]);
		printf(" ");
		j++;
	}
	return 0;
}