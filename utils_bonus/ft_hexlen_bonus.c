#include "ft_printf_bonus.h"

int ft_hexlen_bonus(long long n)
{
    int len;

    len = 0;
    if(n == 0)
        return (0);
    while(n > 0)
    {
        n /= 16;
        len++;
    }
    return (len);
}