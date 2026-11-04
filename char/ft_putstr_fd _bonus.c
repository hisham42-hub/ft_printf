#include "ft_printf_bonus.h"

int	ft_putstr_fd_bonus(char *s, t_format *fmt, int fd)
{
	unsigned int	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	fmt->width -= ft_strlen_bonus(s);
	if(!fmt->minus)
		count += ft_print_pad_bonus(fmt, fd);
	while (s[i])
	{
		count += ft_print_char_bonus(s[i], fd);
		i++;
	}
	if(fmt->minus)
		count += ft_print_pad_bonus(fmt, fd);
	return (count);
}