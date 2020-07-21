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
	int     a = -4;
    int     b = 0;
    char    c = 'a';
    int     d = 2147483647;
    int     e = -2147483648;
    int     f = 42;
    int     g = 25;
    int     h = 4200;
    int     i = 8;
    int     j = -12;
    int     k = 123456789;
    int     l = 0;
    int     m = -12345678;
    char    *n = "abcdefghijklmnop";
    char    *o = "-a";
    char    *p = "-12";
	char    *q = "0";
	char    *r = "%%";
	char    *s = "-2147483648";
	char    *t = "0x12345678";
	char    *u = "-0";

	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
	
	// unsigned long long int 	a = 93940956356327;
	// char	*var = "5";
	// char	*result;
	
	// //printf("<%p %x %X>\n", var, a, a);
	// ft_printf("<%p %x %X>\n", var, a, a);
	// result = itoa(a,'x');
    // printf("itoa = %s\n", result);
    // result = ft_itoabase(a, 16);
	// printf("itoabase = %s\n", result);

	return (0);
}
