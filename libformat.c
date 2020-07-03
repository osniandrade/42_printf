/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:48:41 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/01 20:16:21 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_precisionchar(char *s, t_prtform *form)
{
	char *tmp;

	tmp = s;
	form->chars_in_string = ft_strlen(s);
	if (form->precision >= form->chars_in_string)
		return (s);
	s = ft_substr(s, 0, form->precision);
	free(tmp);
	return (s);
}

char	*ft_precisionint(char *s, t_prtform *form)
{
	int		aux;
	char	*temp;
	char	*temp2;

	form->chars_in_string = ft_strlen(s);
	if (form->precision == 0 && form->negative_int == 0)
	{
		free(s);
		return (NULL);
	}
	aux = (form->precision > form->chars_in_string) ? form->precision - form->chars_in_string : 0;
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
	if (form->padding < 0)
		form->pad_char = ' ';
	form->padding *= (form->padding < 0) ? -1 : 1;
	if (form->siz >= form->padding)
		return (0);
	if (form->precision == 0 && form->has_precision)
		form->pad_char = ' ';
	while (form->siz < form->padding)
	{
		if ((form->precision < form->padding) && form->precision > 0 && form->has_precision)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd(form->pad_char, 1);
		form->siz++;
	}
	return (1);
}

char	*ft_negint(t_prtform *form, int i, char *s)
{
	char	*temp;
	int		c;

	c = 0;
	while (i < 0 && form->pad_char == '0' && (c + ft_strlen(s) + 1) < (int)form->padding)
	{
		temp = ft_strjoin("0", s);
		free(s);
		s = temp;
	}
	if (i < 0 && (form->pad_char == ' ' || (form->has_precision && form->precision < form->padding)))
	{
		temp = ft_strjoin("-", s);
		free(s);
		s = temp;
	}
	
	return (s);
}
