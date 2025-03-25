/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/
#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *number)
{
    int sign = 1;
    int i = 0;
    int result = 0;
    while(number[i] == '\t' || number[i] == ' ')
    {
        i++;
    }
    if(number[i] == '+' || number[i] == '-')
    {
        if(number[i] == '-')
            sign *=-1;
        i++;
    }
    while(number[i] >= '0' && number[i] <= '9')
    {
        result = (result * 10) + (number[i] - '0');
        i++;
    }
    return result * sign;
}

int is_prime(int number)
{
    if(number == 1)
        return 0;
    int i = 2; 
    while(i < number)
    {
        if(number % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void put_nbr(int number)
{   
    char digit = 0;
    if(number >= 10)
    {
        put_nbr(number / 10);
    }
    digit = number % 10 + '0';
    write(1,&digit,1);
}

int main(int argc, char **argv)
{
    int result = 0;
    if(argc == 2)
    {
        if(ft_atoi(argv[1]) < 0)
        {

            write(1,"0\n",2);
        }
        else
        {
            int number = ft_atoi(argv[1]);
            while(number > 0)
            {
                if(is_prime(number))
                    result = result + number;
                number--;
            }
            put_nbr(result);
        }
    }
    else
    {
        write(1,"0\n",2);
    }
}