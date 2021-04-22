/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:04:31 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 20:01:17 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(t_tab *tab)
{
	tab->var_char_int = va_arg(*tab->args, int);
	if (tab->dot == 0 && tab->width == 0)
		ft_putnbr_fd(tab->var_char_int, 1, tab);
	else if (tab->dot == 0 && tab->width != 0)
		if (tab->menos == 1)

		else if (tab->zero == 1)

		else if (tab->menos == 0 && tab->zero == 0)
}
