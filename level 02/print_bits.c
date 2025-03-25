/*

Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

*/

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    int maxbit = 7;
    unsigned char bit;
    while(maxbit >= 0)
    {
        bit = (octet >> maxbit & 1) + '0';
        write(1,&bit,1);
        maxbit--;
    }
}

int main()
{
    print_bits(2);
    return 0;
}