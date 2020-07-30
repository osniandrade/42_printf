/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:42:14 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 16:28:49 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_vprintf(t_prtform *form, va_list lst, int count)
{
	char				*strarg;

	if (form->typ == '%')
		form->siz = ft_pchr('%', form);
	if (ft_testint(form->typ))
		form->siz = ft_redint(va_arg(lst, int), form);
	if (ft_testinttype(form->typ) == 1)
		form->siz = ft_reduint(va_arg(lst, unsigned int), form);
	if (ft_testinttype(form->typ) == 2)
		form->siz = ft_redlint(va_arg(lst, unsigned long int), form);
	if (form->typ == 's')
	{
		strarg = ft_strdup(va_arg(lst, char *));
		form->siz = ft_pstr(strarg, form);
	}
	if (form->typ == 'n')
		ft_pn(count, va_arg(lst, int*));
	form->pad *= (form->pad < 0) ? -1 : 1;
	return (form->siz);
}

int		ft_redint(int n, t_prtform *form)
{
	if (form->typ == 'd' || form->typ == 'i')
		form->siz = ft_pint(n, form);
	if (form->typ == 'c')
		form->siz = ft_pchr(n, form);
	if (form->typ == '%')
		form->siz = ft_pchr('%', form);
	return (form->siz);
}

int		ft_redlint(unsigned long int n, t_prtform *form)
{
	if (form->typ == 'u')
		form->siz = ft_puin(n, form);
	if (form->typ == 'p')
		form->siz = ft_phex(n, form, 2);
	return (form->siz);
}

int		ft_reduint(unsigned int n, t_prtform *form)
{
	if (form->typ == 'x')
		form->siz = ft_phex(n, form, 0);
	if (form->typ == 'X')
		form->siz = ft_phex(n, form, 1);
	return (form->siz);
}

void	ft_pn(int length, int *ptr)
{
	*ptr = length;
}
