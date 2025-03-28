/*

Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

*/
#include <unistd.h>

int str_len(char *str)
{
    int len;
    len = 0;
    while(str[len])
    {
        len++;
    }
    return len;
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int index = str_len(argv[1])-1;
        while(index >= 0)
        {
            write(1,&argv[1][index],1);
            index--;
        }
    }
    write(1,"\n",1);
    return 0;
}