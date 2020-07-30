/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtempa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:32:03 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:24:43 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_isalpha - checks if value is a letter
** ft_strlcat - concatenates a string into another
** ft_strjoin - concatenates two strings, generating a third one
** ft_strdup  - duplicates a string
** ft_toupper - upcases a character
*/

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
