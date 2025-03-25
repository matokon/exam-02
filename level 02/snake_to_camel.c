/*

Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$

*/
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int index = 0;
        int flag = 0;
        while(argv[1][index])
        {
            char letter = argv[1][index];
            if(letter >= 'a' && letter <= 'z' && index == 0)
            {
                write(1,&letter,1);
            }
            else if(letter == '_' && flag == 0)
            {
                flag = 1;
            }
            else if(letter >= 'a' && letter <= 'z' && index != 0 && flag == 1)
            {
                letter = letter - 32;
                flag = 0;
                write(1,&letter,1);
            }
            else if(letter >= 'a' && letter <= 'z' && index != 0 && flag != 1)
            {
                write(1,&letter,1);
            }
            index++;
        }
    }
    return 0;
}