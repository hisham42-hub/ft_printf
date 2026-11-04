#include "ft_printf_bonus.h"

int	ft_putchar_fd_bonus(char c, t_format *fmt, int fd)
{
	int count;

	count = 0;
	if(fmt->width > 0)
		fmt->width -= 1;
	if(!fmt->minus)
		count += ft_print_pad_bonus(fmt, fd);
	count += ft_print_char_bonus(c, fd);
	if(fmt->minus)
		count += ft_print_pad_bonus(fmt, fd);
	return(count);
}
