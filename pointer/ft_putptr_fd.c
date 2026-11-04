#include "ft_printf.h"

int ft_putptr_fd(void *ptr, int fd)
{
    int     count;
    char    *address;

    count = 0;
    address = ptr;
    if(!address)
        return(ft_putstr_fd("(nil)", fd));
    count += ft_putstr_fd("0x", fd);
    count += ft_puthex_fd((unsigned long)address, 'x', fd);
    return (count);
}