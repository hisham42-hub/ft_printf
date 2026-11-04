#include "ft_printf_bonus.h"
static int ft_print_sign_bonus (long long n, t_format *fmt, int fd)
{
    int count;

    count = 0;
    if (n < 0)
    {     
        count += ft_print_char_bonus('-', fd);
    }
    else if (fmt->plus)
      {
         count += ft_print_char_bonus('+', fd);
         if(fmt->width > 0)
            fmt->width -= 1;
      }
    else if (fmt->space)
        count += ft_print_char_bonus(' ', fd);
    
    // if (fmt->width > 0)
    //     fmt->width--;
    return (count);
}

static int	ft_handle_putint_sign_bonus(long long *n, t_format *fmt, int fd)
{
	int	count;

	count = 0;
	if (*n < 0 || fmt->plus || fmt->space)
	{
		count += ft_print_sign_bonus(*n, fmt, fd);
		if (*n < 0)
			*n = -*n;
	}
	return (count);
}

int ft_putint_fd_bonus(long long n, t_format *fmt, int fd)
{
	int	count;
	char	*base_digit;

	count = 0;
	base_digit = "0123456789";
	if (fmt->minus || fmt->dot)
		fmt->zero = 0;
	if (n < 0 && fmt->width > 1)
		fmt->width -= 1;
	if (fmt->zero || fmt->dot)
		count += ft_handle_putint_sign_bonus(&n, fmt, fd);
	count += ft_check_pad_bonus(fmt, n, fd, 10);
	if (!fmt->zero)
		count += ft_handle_putint_sign_bonus(&n, fmt, fd);
	if (!(fmt->dot && fmt->precision == 0 && n == 0))
		count += ft_bs_converter_bonus(n, base_digit, 10, fd);
	if (fmt->minus)
		count += ft_print_pad_bonus(fmt, fd);
	return (count);
}
