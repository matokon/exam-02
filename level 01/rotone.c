/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/
#include <unistd.h>

void  next_letter(char letter)
{
    if(letter >= 'a' && letter <= 'z')
    {
        if(letter + 1 <= 'z')
        {
            letter = letter + 1;
            write(1,&letter,1);
        }
        else
        {
            letter = letter + 1 - 26;
            write(1,&letter,1);
        }
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        if(letter + 1 <= 'Z')
        {
            letter = letter + 1;
            write(1,&letter,1);
        }
        else
        {
            letter = letter + 1 - 26;
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
            next_letter(argv[1][index]);
            index++;
        }
    }
    write(1,"\n",1);
    return 0;
}
