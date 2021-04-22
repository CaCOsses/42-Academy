/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:13:36 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:48:35 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printminus_char(t_tab *tab)
{
	if (tab->menos == 0)
	{
		while (tab->width-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
	ft_putchar_fd(tab->var_char_int, 1, tab);
	if (tab->menos == 1)
	{
		while (tab->width-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
}

/*void	ft_printzero_char(t_tab *tab)
{
	while (tab->width-- > 1)
		ft_putchar_fd('0', 1, tab);
	ft_putchar_fd(tab->var_char, 1, tab);
}*/

void	ft_char(t_tab *tab)
{
	tab->var_char_int = va_arg(*tab->args, int);
	ft_printminus_char(tab);
	/*else if (tab->zero == 1)
		ft_printzero_char(tab);*/
}
