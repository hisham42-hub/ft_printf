#include "ft_printf.h"

int ft_putint_fd(long long n, int fd)
{
   int  count;
   char *base_digit;
   
   count = 0;
   base_digit = "0123456789";
   if(n < 0)
   {
        count += ft_putchar_fd('-', fd);
        n = -n;
   }
   count += ft_base_converter(n, base_digit, 10, fd);
   return (count);
}
