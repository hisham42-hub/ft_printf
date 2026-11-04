#include "ft_printf_bonus.h"
static int hex_base_upper_bonus(unsigned long n, t_format *fmt, int fd)
{
    int count;
    char *base_upper;
    
    base_upper = "0123456789ABCDEF";
    count = 0;
    if (fmt->hash && n != 0)
        count += ft_putstr_fd_bonus("0X", fmt, fd);
    if (fmt->dot)
        count += ft_handle_precision_bonus((long long)n, fmt, fd, 16);
    if(!(fmt->dot && fmt->precision == 0 && n != 0))
        count += ft_bs_converter_bonus(n, base_upper, 16, fd);
    return (count);
}

static int hex_base_lower_bonus(unsigned long n, t_format *fmt, int fd)
{
    int count;
    char *base_lower;
    
    base_lower = "0123456789abcdef";
    count = 0;
    if (fmt->hash && n != 0)
        count += ft_putstr_fd_bonus("0x", fmt, fd);
    if (fmt->dot)
        count += ft_handle_precision_bonus((long long)n, fmt, fd, 16);
    if(!(fmt->dot && fmt->precision == 0 && n != 0))
        count += ft_bs_converter_bonus(n, base_lower, 16, fd);
    return (count);
}

int ft_puthex_fd_bonus (unsigned long n, t_format *fmt, char hx, int fd)
{
    int count;
    t_format tmp_fmt;

    count = 0;
    tmp_fmt = *fmt;
    if(fmt->minus || fmt->dot)
      fmt->zero = 0;
    if(!fmt->minus)
        count += ft_check_pad_bonus(&tmp_fmt, (long long)n, fd, 16);
    if(hx == 'X')
        count += hex_base_upper_bonus(n, fmt, fd);
    else if (hx == 'x')
        count += hex_base_lower_bonus(n, fmt, fd);
    if(fmt->minus)
        count += ft_check_pad_bonus(&tmp_fmt, (long long)n, fd, 16);
    return (count);
}
