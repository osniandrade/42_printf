/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:37:55 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/06/30 16:46:37 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_prtform	*ft_initform(t_prtform *form)
{
	form->padding = 0;
	form->precision = 0;
	form->siz = 0;
	form->neg = 0;
	form->ch_form_str = 0;
	form->pad_char = ' ';
	form->ch_type = ' ';
	form->siz = 0;
	form->chars_in_string = 0;
	form->has_precision = 0;
	form->negative_int = 0;
	return (form);
}

int			ft_countdig(long long int n, int b)
{
	int	i;

	i = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		i++;
		n /= b;
	}
	return (i);
}

void		ft_revstr(char *s, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
		i++;
	}
}

char		*ft_itoabase(unsigned int n, int b)
{
	int		i;
	int		r;
	int		size;
	char	*s;

	i = 0;
	size = ft_countdig(n, b);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		r = n % b;
		s[i++] = (r > 9) ? (r - 10) + 'a' : r + '0';
		n /= b;
	}
	ft_revstr(s, size);
	s[i] = '\0';
	return (s);
}

void		ft_uppercase(char *s)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}
