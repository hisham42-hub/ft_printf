#include "ft_printf_bonus.h"

int ft_handle_precision_bonus(long long n, t_format *fmt, int fd, int base)
{
   int count;
   int len;
   int p_zero;
   
   count = 0;
   if(base == 16)
      len = ft_hexlen_bonus(n);
   else
      len = ft_intlen_bonus(n);
   if (fmt->precision <= len)
      return (0); 
   p_zero = fmt->precision - len;
   while(p_zero > 0)
   {
      count += ft_print_char_bonus('0',fd);
      p_zero--;
   }
   return (count);
}