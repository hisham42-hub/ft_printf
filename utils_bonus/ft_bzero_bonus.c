#include "ft_printf_bonus.h"

void	ft_bzero_bonus(void *s, unsigned int n)
{
	unsigned char	*ptr;
	unsigned int			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
