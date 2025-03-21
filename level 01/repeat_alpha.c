/*

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h>

int to_lower(char character)
{
    if(character >= 'A' && character <= 'Z')
        character = character + 32;
    return character;
}
int is_letter(char character)
{
    if(character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z')
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    int i;
    i = 0;
    int reps;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(is_letter(argv[1][i]))
            {
                reps = to_lower(argv[1][i]) -'a' + 1;
                while(reps > 0)
                {
                    write(1,&argv[1][i],1);
                    reps--;
                }
            }
            else
            {
                write(1,&argv[1][i],1);
            }
            i++;
        }
    }
    write(1,"\n",1);
    return 0;
}