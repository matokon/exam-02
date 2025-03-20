/*

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>

*/
#include <unistd.h>

#define DECIMAL "0123456789"

void write_num(int n) {
	if (n > 9)
		write_num(n / 10);
	write(1, &DECIMAL[n % 10], 1);
}

void main()
{
    int i;
    i = 1;
    while(i <= 100)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            write(1,"fizzbuzz",8);
            write(1,"\n",1);
        }
        else if(i % 3 == 0)
        {
            write(1,"fizz",4);
            write(1,"\n",1);
        }
        else if(i % 5 == 0)
        {
            write(1,"buzz",4);
            write(1,"\n",1);
        }
        else
        {
            write_num(i);
            write(1,"\n",1);
        }
        i++;
    }
}