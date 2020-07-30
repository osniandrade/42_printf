/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:37:55 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:24:29 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_initform     - initializes the format struct
** ft_countdig - counts digits in a int variable
** ft_revstr     - reverses a string
** ft_itoabase  - converts integer to string using base (2, 10, 16, etc)
** ft_uppercase - upcases a string
*/

t_prtform	*ft_initform(t_prtform *form)
{
	form->pad = 0;
	form->prc = 0;
	form->siz = 0;
	form->neg = 0;
	form->chf = 0;
	form->pch = ' ';
	form->typ = ' ';
	form->siz = 0;
	form->cis = 0;
	form->hpr = 0;
	form->ngi = 0;
	return (form);
}

int			ft_countdig(unsigned long long int n, int b)
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

char		*ft_itoabase(unsigned long long int n, int b)
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
