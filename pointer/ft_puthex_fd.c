#include "ft_printf.h"
static int hex_base_upper(unsigned long n, int fd)
{
    int count;
    char *base_upper;
    
    base_upper = "0123456789ABCDEF";
    count = 0;
    count += ft_bs_converter(n, base_upper, 16, fd);
    return (count);
}

static int hex_base_lower(unsigned long n, int fd)
{
    int count;
    char *base_lower;
    
    base_lower = "0123456789abcdef";
    count = 0;
    count += ft_bs_converter(n, base_lower, 16, fd);
    return (count);
}

int ft_puthex_fd (unsigned long n, char hx, int fd)
{
    int count;

    count = 0;
    if(hx == 'X')
        count += hex_base_upper(n, fd);
    else if (hx == 'x')
        count += hex_base_lower(n, fd);
    return (count);
}