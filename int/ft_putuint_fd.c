#include "ft_printf.h"

int ft_putuint_fd(unsigned long n, int fd)
{
   int  count;
   char *base_digit;
   
   count = 0;
   base_digit = "0123456789";
   count += ft_bs_converter(n, base_digit, 10, fd);
   return (count);
}