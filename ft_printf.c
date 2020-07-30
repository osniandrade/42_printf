/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:55:12 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 16:55:02 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_printf   - entry point
** ft_doprintf - sets the formatting structure and test for padding
** 				 necessity
*/

int		ft_doprintf(const char *str, va_list lst)
{
	t_prtform	form;
	int			count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_formparser(&form, str, lst);
			if (form.chf == 0)
				return (0);
			ft_padtest(&form);
			str += form.chf;
			ft_vprintf(&form, lst, count);
			count += (form.pad > form.siz) ? form.pad : form.siz;
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			count++;
		}
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	result = ft_doprintf((char *)str, args);
	va_end(args);
	return (result);
}
