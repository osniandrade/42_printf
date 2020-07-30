/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:36:00 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:09:26 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_fp_precision - checks for precision value in the format string
** ft_fp_width     - checks the size of the format string
** ft_fp_flag      - checks for flags in the format string
** ft_formparser   - entry point to define the format struct
*/

t_prtform	*ft_fp_precision(t_prtform *form, char *str, va_list lst)
{
	if (*str == '.')
	{
		str++;
		form->hpr = 1;
		form->chf += 1;
		if (ft_isdigit(*str))
		{
			form->prc = ft_atoi((char *)str);
			while (ft_isdigit(*str) && str++)
				form->chf++;
		}
		else if (*str == '*')
		{
			form->prc = va_arg(lst, int);
			str++;
			form->chf++;
		}
	}
	if (ft_isvalid(form, str))
	{
		form->typ = *str++;
		form->chf++;
	}
	return (form);
}

t_prtform	*ft_fp_width(t_prtform *form, char *str, va_list lst)
{
	if (ft_isdigit(*str) || *str == '*')
	{
		if (ft_isdigit(*str))
		{
			form->pad = ft_atoi((char *)str);
			while (ft_isdigit(*str))
			{
				str++;
				form->chf++;
			}
		}
		else if (*str == '*')
		{
			form->pad = va_arg(lst, int);
			form->neg = form->pad < 0 ? 1 : form->neg;
			str++;
			form->chf++;
		}
	}
	form->pad *= (form->neg && form->pad > 0) ? -1 : 1;
	return (ft_fp_precision(form, str, lst));
}

t_prtform	*ft_fp_flag(t_prtform *form, char *str, va_list lst)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			form->neg = *str == '-' ? 1 : 0;
		if (*str == '0')
			form->pch = *str == '0' ? '0' : ' ';
		str++;
		form->chf++;
	}
	form->pch = form->neg ? ' ' : form->pch;
	return (ft_fp_width(form, str, lst));
}

t_prtform	*ft_formparser(t_prtform *form, char const *str, va_list lst)
{
	ft_initform(form);
	return (ft_fp_flag(form, (char*)str, lst));
}
