/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtempb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:32:03 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:27:57 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_substr     - reduces a string from a defined position
** ft_strlen     - returns the size of a string
** ft_strlcpy    - copies a string into another
** ft_strchr     - checks for the presence of a character in a
**                 string
** ft_putchar_fd - prints a single character
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((slen == 0) || (start > (slen - len)) || (len > slen))
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (*s == '\0')
		return (0);
	while (*s++ != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	int		old;

	i = -1;
	old = 0;
	if (!dst || !src)
		return (0);
	while (src[old] != '\0')
		old++;
	if (size == 0)
		return (old);
	if (size > 0)
		while ((src[++i] != '\0') && (i < (int)(size - 1)))
			dst[i] = src[i];
	dst[i] = '\0';
	return (old);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != c)
		s++;
	return (s);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
