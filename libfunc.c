/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:25:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/06/30 16:46:31 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printpad(t_prtform *form, char *s)
{
	if (!s && form->has_precision && !form->precision && form->pad_char == '0')
		form->pad_char = ' ';
	if (form->padding > 0)
		ft_padding(form);
	ft_putstr_fd(s, 1);
	if (form->padding < 0)
		ft_padding(form);
	free(s);
}