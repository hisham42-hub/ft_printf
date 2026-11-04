#include "ft_printf_bonus.h"

int  ft_isflag_bonus(char c)
{
    if(c == '-' || c == '+' || c == ' ' || c == '0' || c == '#' || c == '.')
        return (1);
    return (0);
}