/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:42:14 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/01 19:19:00 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_vprintf(t_prtform *form, va_list lst, int count)
{
	char			*strarg;
	int				argint;
	unsigned int	argllint;

	if (form->ch_type == '%')
		form->siz = ft_pchr('%', form);
	if (ft_testint(form->ch_type))
	{
		argint = va_arg(lst, int);
		form->siz = ft_redint(argint, form);
	}
	if (ft_testllint(form->ch_type))
	{
		argllint = va_arg(lst, unsigned int);
		form->siz = ft_redllint(argllint, form);
	}
	if (form->ch_type == 's')
	{
		strarg = ft_strdup(va_arg(lst, char *));
		form->siz = ft_pstr(strarg, form);
	}
	if (form->ch_type == 'n')
		ft_pn(count, va_arg(lst, int*));
	form->padding *= (form->padding < 0) ? -1 : 1;
	return (form->siz);
}

int		ft_redint(int n, t_prtform *form)
{
	if (form->ch_type == 'd' || form->ch_type == 'i')
		form->siz = ft_pint(n, form);
	if (form->ch_type == 'c')
		form->siz = ft_pchr(n, form);
	if (form->ch_type == '%')
		form->siz = ft_pchr('%', form);
	return (form->siz);
}

int		ft_redllint(unsigned int n, t_prtform *form)
{
	if (form->ch_type == 'u')
		form->siz = ft_puin(n, form);
	if (form->ch_type == 'x')
		form->siz = ft_phex(n, form, 0);
	if (form->ch_type == 'X')
		form->siz = ft_phex(n, form, 1);
	if (form->ch_type == 'p')
		form->siz = ft_phex(n, form, 2);
	return (form->siz);
}

void	ft_pn(int length, int *ptr)
{
	*ptr = length;
}
