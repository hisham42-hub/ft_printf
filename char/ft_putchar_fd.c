#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int count;

	count = 0;
	count += ft_print_char(c, fd);

	return(count);
}
