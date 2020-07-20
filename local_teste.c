#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int		digitcounter(unsigned long int n)
{
	if (!(n / 16))
		return (1);
	else
		return (digitcounter(n / 16) + 1);
}

char	*itoa(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = digitcounter(n);
	if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

int		main(void)
{
	char *var = "5";
	
	ft_printf("<%p>\n", var);
	printf("<%p>\n", var);

	int 	a = 1431679840;
    //char 	buffer[30];
	char	*result;

    result = itoa(a,'x');
    printf("itoa = %s\n", result);

    result = ft_itoabase(a, 16);
	printf("itoabase = %s\n", result);

	return (0);
}
