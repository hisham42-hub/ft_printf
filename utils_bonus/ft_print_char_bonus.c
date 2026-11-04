#include "ft_printf_bonus.h"

int ft_print_char_bonus(char c, int fd)
{
    return (write(fd, &c, 1));
}