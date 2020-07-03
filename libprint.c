/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:45:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/01 19:37:24 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pchr(char c, t_prtform *form)
{
	form->siz = 1;
	if (form->padding > 0)
		ft_padding(form);
	ft_putchar_fd(c, 1);
	if (form->padding < 0)
		ft_padding(form);
	return (1);
}

int		ft_phex(unsigned int i, t_prtform *form, int swt)
{
	char	*s;
	char	*temp;

	form->negative_int = i;
	s = ft_itoabase(i, 16);
	if (form->has_precision)
		s = ft_precisionint(s, form);
	form->siz = ft_strlen(s);
	if (swt == 1)
		ft_uppercase(s);
	if (!i && !form->precision && form->has_precision)
	{
		free(s);
		s = NULL;
	}
	if (swt == 2)
	{
		temp = ft_strjoin("0x", s);
		free(s);
		s = temp;
		form->siz += 2;
	}
	ft_printpad(form, s);
	return (form->siz);
}

int		ft_pint(long i, t_prtform *form)
{
	char	*s;
	long	num;

	num = (i < 0) ? i * -1 : i;
	form->negative_int = 1;
	s = (ft_testprcpad(form, num)) ? ft_strdup("") : ft_itoabase(num, 10);
	if (form->has_precision)
		s = ft_precisionint(s, form);
	s = ft_negint(form, i, s);
	form->siz = ft_strlen(s);
	if (i < 0 && form->pad_char == '0' && !(form->has_precision && form->precision < form->padding))
	{
		ft_putchar_fd('-', 1);
		form->siz++;
	}
	//imprime espaço se numero, caracter de padding e precision forem 0
	if (i == 0 && form->padding == 1 && form->has_precision && form->precision == 0)
	{
		ft_putchar_fd(' ', 1);
		form->siz++;
	}
	//fim da alteração
	ft_printpad(form, s);
	return (form->siz);
}

int		ft_pstr(char *s, t_prtform *form)
{
	if (!s)
	{
		s = ft_strdup("(null)");
	}
	if (form->has_precision)
		s = ft_precisionchar(s, form);
	form->siz = ft_strlen(s);
	ft_printpad(form, s);
	return (form->siz);
}

int		ft_puin(unsigned int i, t_prtform *form)
{
	char	*s;

	form->negative_int = i;
	s = ft_itoabase(i, 10);
	if (form->has_precision)
		s = ft_precisionint(s, form);
	form->siz = ft_strlen(s);
	if (!i && !form->precision && form->has_precision)
	{
		free(s);
		s = NULL;
	}
	ft_printpad(form, s);
	return (form->siz);
}
