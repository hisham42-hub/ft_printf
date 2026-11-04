#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		count += ft_print_char(s[i], fd);
		i++;
	}
	return (count);
}