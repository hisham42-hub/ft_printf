#include "ft_printf.h"
int ft_intlen_bonus(long long n)
{
    int len;
    long long temp_n;

    len = 0;
    temp_n = n;
    if(temp_n < 0)
        temp_n = -temp_n;
    if (temp_n == 0)
        return (1);
    while (temp_n > 0)
    {
        temp_n = temp_n/10;
        len++;
    }
    return (len);
}