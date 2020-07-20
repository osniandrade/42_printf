#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	char *var = "5";
	
	ft_printf("<%p>", var);
	ft_printf("\n");
	printf("<%p>", var);
	printf("\n");
	
	return (0);
}
