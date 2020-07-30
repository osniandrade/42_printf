/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:45:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 10:15:26 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pchr(char c, t_prtform *form)
{
	form->siz = 1;
	if (form->pad > 0)
		ft_padding(form);
	ft_putchar_fd(c, 1);
	if (form->pad < 0)
		ft_padding(form);
	return (1);
}

int		ft_phex(unsigned long long int i, t_prtform *form, int swt)
{
	char	*s;
	char	*temp;

	form->ngi = i;
	s = ft_itoabase(i, 16);
	if (form->hpr)
		s = ft_precisionint(s, form);
	form->siz = ft_strlen(s);
	if (swt == 1)
		ft_uppercase(s);
	if (!i && !form->prc && form->hpr)
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

int		ft_phex_ui(unsigned int i, t_prtform *form, int swt)
{
	char	*s;
	char	*temp;

	form->ngi = i;
	s = ft_itoabase_ui(i, 16);
	if (form->hpr)
		s = ft_precisionint(s, form);
	form->siz = ft_strlen(s);
	if (swt == 1)
		ft_uppercase(s);
	if (!i && !form->prc && form->hpr)
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

int		ft_pint(long int i, t_prtform *form)
{
	char	*s;
	long	num;

	num = (i < 0) ? i * -1 : i;
	form->ngi = 1;
	s = (ft_testprcpad(form, num)) ? ft_strdup("") : ft_itoabase(num, 10);
	if (form->hpr)
		s = ft_precisionint(s, form);
	s = ft_negint(form, i, s);
	form->siz = ft_strlen(s);
	if (i < 0 && form->pch == '0' && !(form->hpr && form->prc < form->pad))
	{
		ft_putchar_fd('-', 1);
		form->siz++;
	}
	if (i == 0 && form->pad == 1 && form->hpr && form->prc == 0)
	{
		ft_putchar_fd(' ', 1);
		form->siz++;
	}
	ft_printpad(form, s);
	return (form->siz);
}

int		ft_pstr(char *s, t_prtform *form)
{
	if (!s)
	{
		s = ft_strdup("(null)");
	}
	if (form->hpr)
		s = ft_precisionchar(s, form);
	form->siz = ft_strlen(s);
	ft_printpad(form, s);
	return (form->siz);
}

int		ft_puin(unsigned int i, t_prtform *form)
{
	char	*s;

	form->ngi = i;
	s = ft_itoabase(i, 10);
	if (form->hpr)
		s = ft_precisionint(s, form);
	form->siz = ft_strlen(s);
	if (!i && !form->prc && form->hpr)
	{
		free(s);
		s = NULL;
	}
	ft_printpad(form, s);
	return (form->siz);
}
