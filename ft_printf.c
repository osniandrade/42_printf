/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:55:12 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/06/30 16:46:33 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			if (form.ch_form_str == 0)
				return (0);
			ft_padtest(&form);
			str += form.ch_form_str;
			ft_vprintf(&form, lst, count);
			count += (form.padding > form.siz) ? form.padding : form.siz;
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
