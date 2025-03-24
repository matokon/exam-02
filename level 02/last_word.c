/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int len = 0;

        while (argv[1][len])
            len++;
        len--;

        while (len >= 0 && (argv[1][len] == ' ' || argv[1][len] == '\t'))
            len--;
        
        int end = len;
        while (len >= 0 && argv[1][len] != ' ' && argv[1][len] != '\t')
            len--;
        len++;
        while (len <= end)
        {
            write(1, &argv[1][len], 1);
            len++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
