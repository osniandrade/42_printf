/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:48:41 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:28:10 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_precisionchar - checks if precision value is less than
**                    characters in string
** ft_precisionint  - checks and prints the 0 padding for int
** 					  values
** ft_padding       - checks and prints the padding character
** ft_negint	    - adjusts the padding and prints the - sign
** 					  on negative numbers
*/

char	*ft_precisionchar(char *s, t_prtform *form)
{
	char *tmp;

	tmp = s;
	form->cis = ft_strlen(s);
	if (form->prc >= form->cis)
		return (s);
	s = ft_substr(s, 0, form->prc);
	free(tmp);
	return (s);
}

char	*ft_precisionint(char *s, t_prtform *form)
{
	int		aux;
	char	*temp;
	char	*temp2;

	form->cis = ft_strlen(s);
	if (form->prc == 0 && form->ngi == 0)
	{
		free(s);
		return (NULL);
	}
	aux = (form->prc > form->cis) ? form->prc - form->cis : 0;
	if (aux == 0)
		return (s);
	temp = (char *)malloc(sizeof(char) * (aux + 1));
	temp[aux] = '\0';
	while (--aux > -1)
		temp[aux] = '0';
	temp2 = ft_strjoin(temp, s);
	free(temp);
	free(s);
	return (temp2);
}

int		ft_padding(t_prtform *form)
{
	if (form->pad < 0)
		form->pch = ' ';
	form->pad *= (form->pad < 0) ? -1 : 1;
	if (form->siz >= form->pad)
		return (0);
	if (form->prc == 0 && form->hpr)
		form->pch = ' ';
	while (form->siz < form->pad)
	{
		if ((form->prc < form->pad) && form->prc > 0 && form->hpr)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd(form->pch, 1);
		form->siz++;
	}
	return (1);
}

char	*ft_negint(t_prtform *form, int i, char *s)
{
	char	*temp;
	size_t	c;
	size_t	p;

	c = ft_strlen(s) + 1;
	p = form->pad;
	if (c < p && i < 0 && form->pch == '0' && form->pad > 0 && form->prc < 0)
	{
		while (c < p)
		{
			temp = ft_strjoin("0", s);
			free(s);
			s = temp;
			c++;
		}
	}
	if (i < 0 && (form->pch == ' ' || (form->hpr && form->prc < form->pad)))
	{
		temp = ft_strjoin("-", s);
		free(s);
		s = temp;
	}
	return (s);
}
