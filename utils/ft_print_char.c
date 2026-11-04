#include "ft_printf.h"

int ft_print_char(char c, int fd)
{
    return (write(fd, &c, 1));
}