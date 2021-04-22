/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:08:48 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:48:52 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*initialize(t_tab *tab)
{
	tab->len = 0;
	tab->precision = 0;
	tab->menos = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->width = 0;
	tab->dot = 0;
	tab->var_char_int = 0;
	tab->var_str = 0;
	tab->args = 0;
	return (tab);
}

void	reinitialize(t_tab *tab)
{
	tab->precision = 0;
	tab->menos = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->width = 0;
	tab->dot = 0;
	tab->var_char_int = 0;
	tab->var_str = 0;
}
