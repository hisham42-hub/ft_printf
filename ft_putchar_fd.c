#include "ft_printf.h"
int	ft_putchar_fd(char c, int fd)
{
	unsigned int	i;

	i = 1;
	write(fd, &c, i);
	return(1)
}