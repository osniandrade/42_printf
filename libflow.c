/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:42:14 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/21 16:25:39 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_vprintf(t_prtform *form, va_list lst, int count)
{
	char			*strarg;
	int				argint;
	unsigned long long int	argllint; //***********************mudar aqui

	if (form->typ == '%')
		form->siz = ft_pchr('%', form);
	if (ft_testint(form->typ))
	{
		argint = va_arg(lst, int);
		form->siz = ft_redint(argint, form);
	}
	if (ft_testllint(form->typ))
	{
		argllint = va_arg(lst, unsigned long long int); //*********mudar aqui
		form->siz = ft_redllint(argllint, form);
	}
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

int		ft_redllint(unsigned long long int n, t_prtform *form) //***mudar aqui
{
	if (form->typ == 'u')
		form->siz = ft_puin(n, form);
	if (form->typ == 'x')
		form->siz = ft_phex(n, form, 0);
	if (form->typ == 'X')
		form->siz = ft_phex(n, form, 1);
	if (form->typ == 'p')
		form->siz = ft_phex(n, form, 2);
	return (form->siz);
}

void	ft_pn(int length, int *ptr)
{
	*ptr = length;
}
