#include "ft_printf.h"

int ft_putuint_fd(unsigned long n, int fd)
{
   int  count;
   char *base;
   
   count = 0;
   base = "0123456789";
   count += ft_bs_converter(n, base, 10, fd);
   return (count);
}