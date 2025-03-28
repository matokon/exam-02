/*

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int index;
    index = 0;
    while(argv[1][index])
    {
        if(argv[1][index] >= 'A' && argv[1][index] <= 'Z')
        {
            write(1,"_",1);
            char letter;
            letter = argv[1][index] + 32; 
            write(1,&letter,1);
        }
        else
        {
            write(1,&argv[1][index],1);
        }
        index ++;
    }
    return 0;
}