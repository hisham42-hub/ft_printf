#include "ft_printf_bonus.h"

int ft_putuint_fd_bonus(unsigned long n, t_format *fmt, int fd)
{
   int  count;
   char *base_digit;
   long long num;
   
   count = 0;
   base_digit = "0123456789";
   num = (long long)n;
   if(fmt->minus || fmt->dot)
      fmt->zero = 0;
   count += ft_check_pad_bonus(fmt, num, fd, 10);
   if(!(fmt->dot && fmt->precision == 0 && n == 0))
      count += ft_bs_converter_bonus(n, base_digit, 10, fd);
   if(fmt->minus)
      count += ft_print_pad_bonus(fmt, fd);
   return (count);
}
