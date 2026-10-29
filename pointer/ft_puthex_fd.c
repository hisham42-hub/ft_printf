#include "ft_printf.h"

int ft_puthex_fd (unsigned long n, char hx,fd)
{
    char *base_upper;
    char *base_lower;
    int count;

    count = 0;
    base_upper = "0123456789ABCDEF";
    base_lower = "0123456789abcdef";
    if(hx == 'X')
        count += ft_base_converter(n, base_upper, 16, fd);
    else
        count += ft_base_converter(n, base_lower, 16, fd);
    return (count);
}