/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:49:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/01 19:47:27 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_testint(char c)
{
	if (*ft_strchr("cid", c) == c)
		return (1);
	else
		return (0);
}

int		ft_testllint(char c)
{
	if (*ft_strchr("uxXp", c) == c)
		return (1);
	else
		return (0);
}

int		ft_isvalid(t_prtform *form, char *str)
{
	if (*ft_strchr("%csiduxpXn", *str) == *str && *str != '\0')
	{
		if (*str == 's' && form->has_precision && form->precision < 0)
			form->has_precision = 0;
		return (1);
	}
	else
		return (0);
}

void	ft_padtest(t_prtform *form)
{
	if (*ft_strchr("cp", form->ch_type) == form->ch_type)
		form->pad_char = ' ';
}

int		ft_testprcpad(t_prtform *form, int num)
{
	if (form->has_precision && !form->precision && !num)
		return (1);
	return (0);
}
