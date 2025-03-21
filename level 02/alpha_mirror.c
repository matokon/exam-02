/*

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
 
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.
 
Examples:
 
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/
#include <unistd.h>
void opposite_character(char letter)
{
    if(letter >= 'a' && letter <= 'z')
    {
        char helper_letter = 'a';
        int index = 0;
        while(helper_letter != letter)
        {
            helper_letter++;
            index++;
        }
        char new_letter = 'z' - index;
        write(1,&new_letter,1);
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        char helper_letter = 'A';
        int index = 0;
        while(helper_letter != letter)
        {
            helper_letter++;
            index++;
        }
        char new_letter = 'Z' - index;
        write(1,&new_letter,1);
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
            opposite_character(argv[1][index]);
            index++;
        }
    }
    write(1,"\n",1);
}