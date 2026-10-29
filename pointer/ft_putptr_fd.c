#include "ft_printf.h"

int ft_putptr_fd(void *ptr, int fd)
{
    int     count;
    char    *address;
    char    *base;

    count = 0;
    base = "0123456789abcdef";
    address = ptr;
    if(!address)
        return(ft_putstr_fd("(nil)",1));
    count += ft_putstr_fd("0x",fd);
    count += ft_puthex_fd((unsigned long long)address, 'x',1);
    return (count);
}