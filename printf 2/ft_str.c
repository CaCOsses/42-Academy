/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:07:32 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:13:02 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printminus_str(t_tab *tab)
{
	int i;

	i = (tab->width) - ft_strlen(tab->var_str) + 1;
	if (tab->menos == 0)
	{
		while (i-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
	while (*tab->var_str)
	{
		ft_putchar_fd(*tab->var_str, 1, tab);
		tab->var_str++;
	}
	if (tab->menos == 1)
	{
		while (i-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
}

void	ft_printpreci_str(t_tab *tab)
{
	while (tab->precision-- > 0 && *tab->var_str)
	{
		ft_putchar_fd(*tab->var_str, 1, tab);
		tab->var_str++;
	}
}

void	ft_printprecimin_str(t_tab *tab)
{
	int i;
	
	i = (tab->width) - (tab->precision) + 1;
	if (tab->menos == 0)
	{
		if (ft_strlen(tab->var_str) < (tab->precision))
			i =tab->width - ft_strlen(tab->var_str) + 1;
		while (i-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
	while (tab->precision-- > 0 && *tab->var_str)
	{
		ft_putchar_fd(*tab->var_str, 1, tab);
		tab->var_str++;
	}
	if (tab->menos == 1)
	{
		while (i-- > 1)
			ft_putchar_fd(' ', 1, tab);
	}
}

void	ft_print_str(t_tab *tab)
{
	while (*tab->var_str)
	{
		ft_putchar_fd(*tab->var_str, 1, tab);
		tab->var_str++;
	}
}

void	ft_str(t_tab *tab)
{
	tab->var_str = va_arg(*tab->args, char *);
	if (tab->var_str == 0)
		tab->var_str = "(null)";
	if (tab->dot == 0 && tab->width > 0)
		ft_printminus_str(tab);
	else if (tab->dot == 1 && tab->width == 0)
		ft_printpreci_str(tab);
	else if (tab->dot == 1 && tab->width != 0)
		ft_printprecimin_str(tab);
	else if (tab->dot == 0 && tab->width == 0)
		ft_print_str(tab);
}
