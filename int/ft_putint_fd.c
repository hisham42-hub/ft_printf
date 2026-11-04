#include "ft_printf.h"

int ft_putint_fd(long long n, int fd)
{
	int	count;
	char	*base_digit;

	count = 0;
	base_digit = "0123456789";
	if (n < 0)
	{
		n = -n;
		count += ft_print_char('-', fd);
	}
	count += ft_bs_converter(n, base_digit, 10, fd);
	return (count);
}