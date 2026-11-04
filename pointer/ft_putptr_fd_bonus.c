#include "ft_printf_bonus.h"

int ft_putptr_fd_bonus(void *ptr, t_format *fmt, int fd)
{
    int     count;
    char    *address;

    count = 0;
    address = ptr;
    fmt->hash = 0;
    if(!address)
        return(ft_putstr_fd_bonus("(nil)", fmt, fd));
    count += ft_putstr_fd_bonus("0x", fmt, fd);
    count += ft_puthex_fd_bonus((unsigned long)address, fmt, 'x', fd);
    return (count);
}