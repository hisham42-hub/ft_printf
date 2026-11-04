#include "ft_printf_bonus.h"

int ft_print_pad_bonus (t_format *fmt, int fd)
{
    int count;

    count = 0;
    while(fmt->width > 0)
    {
        if(fmt->zero)
        {			
            count += ft_print_char('0', fd);
			fmt->width--;
        }
        else
        {
			count += ft_print_char(' ', fd);
			fmt->width--;
        }
    }
    return (count);
}

int ft_check_pad_bonus(t_format *fmt, long long n, int fd, int base)
{
    int count;
    int len;
    int printed_len;

    count = 0;
    // total len
    if (base == 16)
        len = ft_hexlen_bonus((unsigned long)n);
    else
    {
        if (n < 0)
            n = -n;
        len = ft_intlen_bonus(n);
    }

    // calc pading
    printed_len = len;
    if (fmt->dot && fmt->precision > len)
        printed_len = fmt->precision;
    if (base == 16 && fmt->hash && n != 0)
    {
        // count += ft_putstr_fd("0X",fmt,fd);
        if (fmt->width >= 2)
            fmt->width -= 2;
    }
    if (fmt->width >= printed_len)
        fmt->width -= printed_len;
    else
        fmt->width = 0;
    // print pad
    if (!fmt->minus && (fmt->width > 0))
        count += ft_print_pad_bonus(fmt, fd);

    if (fmt->dot && base != 16)
        count += ft_handle_precision_bonus(n, fmt, fd, base);
    return (count);
}
