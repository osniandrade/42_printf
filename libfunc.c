/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:25:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/07/30 17:06:21 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_printpad - prints the padding where needed
*/

void	ft_printpad(t_prtform *form, char *s)
{
	if (!s && form->hpr && !form->prc && form->pch)
		form->pch = ' ';
	if (form->pad > 0)
		ft_padding(form);
	ft_putstr_fd(s, 1);
	if (form->pad < 0)
		ft_padding(form);
	free(s);
}
