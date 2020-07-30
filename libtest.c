/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:49:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:22:25 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_testint     - tests if flag is for integer or single character
** ft_testinttype - tests type of int: unsigned int or unsigned long int
** ft_padtest     - changes the padding character, if needed
** ft_testprcpad  - tests if value to be printed can have precision
*/

int		ft_testint(char c)
{
	if (*ft_strchr("cid", c) == c)
		return (1);
	else
		return (0);
}

int		ft_testinttype(char c)
{
	if (*ft_strchr("xX", c) == c)
		return (1);
	if (*ft_strchr("up", c) == c)
		return (2);
	else
		return (0);
}

int		ft_isvalid(t_prtform *form, char *str)
{
	if (*ft_strchr("%csiduxpXn", *str) == *str && *str != '\0')
	{
		if (*str == 's' && form->hpr && form->prc < 0)
			form->hpr = 0;
		return (1);
	}
	else
		return (0);
}

void	ft_padtest(t_prtform *form)
{
	if (*ft_strchr("cp", form->typ) == form->typ)
		form->pch = ' ';
}

int		ft_testprcpad(t_prtform *form, int num)
{
	if (form->hpr && !form->prc && !num)
		return (1);
	return (0);
}
