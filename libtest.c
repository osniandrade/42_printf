/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:49:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/29 16:13:20 by ocarlos-         ###   ########.fr       */
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

int		ft_testuint(char c)
{
	if (*ft_strchr("p", c) == c)
		return (1);
	else
		return (0);
}

int		ft_testllint(char c)
{
	if (*ft_strchr("uxX", c) == c)
		return (1);
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
