/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

*/
#include <unistd.h>

void rot_13(char letter)
{
    if(letter >= 'a' && letter <= 'z')
    {
        if(letter + 13 <= 122)
        {
            letter = letter + 13;
            write(1,&letter,1);
        }
        else
        {
            letter = letter + 13 - 26;
            write(1,&letter,1);
        }
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        if(letter + 13 <= 95)
        {
            letter = letter + 13;
            write(1,&letter,1);
        }
        else
        {
            letter = letter + 13 - 26;
            write(1,&letter,1);
        }
    }
    else
    {
        write(1,&letter,1);
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int index;
        index = 0;
        while(argv[1][index])
        {
            rot_13(argv[1][index]);
            index ++;
        }
    }
    write(1,"\n",1);
    return 0;
}