#include "ft_printf_bonus.h"
int ft_isconversion_bonus(char c)
{
    if(c == 'c' || c == 's'|| c == 'i' || c == 'u' || c == 'p')
        return (1);
    else if(c== 'd' || c == 'x' || c == 'X'|| c == '%')
        return (1);
    return (0);
}