/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtemp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:32:03 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/05/26 20:39:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_isalpha(int c)
{
	if ((c < 65) || (c > 122))
		return (0);
	else if ((c > 90) && (c < 97))
		return (0);
	else
		return (1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dstsize;

	i = 0;
	j = 0;
	dstsize = 0;
	while (src[dstsize] != '\0')
		dstsize++;
	while (dst[i] && (i < size))
		i++;
	while (src[j] && ((i + j + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = '\0';
	return (i + dstsize);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		total;

	total = (s1 && s2) ? (ft_strlen(s1) + ft_strlen(s2)) : 0;
	if (!(result = (char *)malloc(sizeof(char) * total + 1)))
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ft_strlcpy(result, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(result, (char *)s2, total + 1);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!(dst = malloc(size + 1)))
		return (0);
	ft_memcpy(dst, s1, size);
	dst[size] = '\0';
	return (dst);
}

int		ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		c -= 32;
	return (c);
}

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
