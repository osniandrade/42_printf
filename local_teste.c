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
// 	int     a = -4;
	
// 	ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1
// , a, 1, a, NULL, a, 0);
// 	printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1
// , a, 1, a, NULL, a, 0);
	
	int 	a = 1431679840;
	char	*var = "5";
	char	*result;
	
	printf("<%p>\n", var);
	ft_printf("<%p>\n", var);
	result = itoa(a,'x');
    printf("itoa = %s\n", result);
    result = ft_itoabase(a, 16);
	printf("itoabase = %s\n", result);

	return (0);
}
