#include "ft_printf.h"
int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return ;
	while (s[i])
	{
		count += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (count);
}
