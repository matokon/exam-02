/*

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

*/
#include <stdlib.h>
#include <stdio.h>

int length(int start, int end)
{
    int i = 0;
    if(start == end) return 1;
    else if(start < end)
    {
        return(end-start+1);
    }
    else
    {
        return(start-end+1);
    }
}

int     *ft_range(int start, int end)
{
    int len = length(start, end);
    int *array;
    int i = 0;
    array = (int*)malloc(sizeof(int)*len);
    if(!array)
        return NULL;
    if(start > end)
    {
        while(start > end)
        {
            array[i] = start;
            start--;
            i++;
        }
    }
    else if(start < end)
    {
        while(start < end)
        {
            array[i] = start;
            start++;
            i++;
        }
    }
    array[i] = end;
    return array;
}

int main()
{
    int *array = ft_range(0, 0);
    if (!array)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int len = length(0, 0);
    for (int i = 0; i < len; i++)
    {
        printf("%d   ", array[i]);
    }

    printf("\n");

    free(array);
    return 0;
}