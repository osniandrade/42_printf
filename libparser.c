/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:36:00 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/06/30 16:46:32 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_prtform	*ft_fp_precision(t_prtform *form, char *str, va_list lst)
{
	if (*str == '.')
	{
		str++;
		form->has_precision = 1;
		form->ch_form_str += 1;
		if (ft_isdigit(*str))
		{
			form->precision = ft_atoi((char *)str);
			while(ft_isdigit(*str)) {
				str++;
				form->ch_form_str++;
			}
		} else if (*str == '*') {
			form->precision = va_arg(lst, int);
			str++;
			form->ch_form_str++;
		}
	}
	if (ft_isvalid(form, str))
	{
		form->ch_type = *str++;
		form->ch_form_str++;
	}
	return (form);
}

t_prtform	*ft_fp_width(t_prtform *form, char *str, va_list lst)
{
	if (ft_isdigit(*str) || *str == '*')
	{
		if (ft_isdigit(*str))
		{
			form->padding = ft_atoi((char *)str);
			while(ft_isdigit(*str)) {
				str++;
				form->ch_form_str++;
			}
		} else if (*str == '*') {
			form->padding = va_arg(lst, int);
			form->neg = form->padding < 0 ? 1 : form->neg;
			str++;
			form->ch_form_str++;
		}
	}
	form->padding *= (form->neg && form->padding > 0) ? -1 : 1;
	return (ft_fp_precision(form, str, lst));
}

t_prtform	*ft_fp_flag(t_prtform *form, char *str, va_list lst)
{
	while (*str == '-' || *str == '0')
	{

		if (*str == '-')
			form->neg = *str == '-' ? 1 : 0;
		if (*str == '0')
			form->pad_char = *str == '0' ? '0' : ' ';
		str++;
		form->ch_form_str++;
	}
	form->pad_char = form->neg ? ' ' : form->pad_char;
	return (ft_fp_width(form, str, lst));
}

t_prtform	*ft_formparser(t_prtform *form, char const *str, va_list lst)
{
	ft_initform(form);
	return (ft_fp_flag(form, (char*)str, lst));
}
