/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtempc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:32:03 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:28:21 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_putstr_fd - prints a string
** ft_memcpy    - copies the content of a memory address to another
** ft_isdigit   - checks if the value is a number
** ft_atoi      - converts a number from character form to int
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

int		ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_atoi(char *s)
{
	int		n;

	n = *s++ - '0';
	while (ft_isdigit(*s))
		n = (*s++ - '0') + (n * 10);
	return (n);
}
