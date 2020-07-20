#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

	char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

int		main(void)
{
	char *var = "5";
	
	ft_printf("<%p>\n", var);
	printf("<%p>\n", var);

	int 	a = 1431679840;
    char 	buffer[30];
	char	*result;

    itoa(a,buffer,16);   // here 16 means Hexadecimal
    printf("itoa = %s\n", buffer);

    result = ft_itoabase(a, 16);
	printf("itoabase = %s\n", result);

	return (0);
}
