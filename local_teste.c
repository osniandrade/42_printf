#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("<%0*.*d>", 4, -2, -12);
	ft_printf("\n");
	return (0);
}
