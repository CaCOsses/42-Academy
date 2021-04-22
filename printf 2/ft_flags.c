/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:38:10 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:16:40 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zerominus(t_tab *tab)
{
	while (*tab->format == '0' || *tab->format == '-')
	{
		if (*tab->format == '0' && tab->menos == 0)
			tab->zero = 1;
		else if (*tab->format == '-')
		{
			tab->menos = 1;
			tab->zero = 0;
		}
		tab->format++;
	}
}

void	ft_width(t_tab *tab)
{
	if (*tab->format == '*')
	{
		tab->width = va_arg(*tab->args, int);
		if (tab->width < 0)
		{
			tab->menos = 1;
			tab->zero = 0;
		}
		tab->format++;
	}
	if (*tab->format >= '0' && *tab->format <= '9')
		tab->width = atoi(tab->format);
	while (*tab->format >= '0' && *tab->format <= '9')
		tab->format++;
}

void	ft_precision(t_tab *tab)
{
	if(*tab->format == '.')
	{
		tab->format++;
		tab->dot = 1;
		if (*tab->format == '*')
		{
			tab->precision = va_arg(*tab->args, int);
			tab->format++;
		}
		if (*tab->format >= '0' && *tab->format <= '9')
			tab->precision = atoi(tab->format);
		while (*tab->format >= '0' && *tab->format <= '9')
			tab->format++;
	}
}

void	ft_type(t_tab *tab)
{
	if (*tab->format == 'c')
		ft_char(tab);
	else if (*tab->format == 's')
		ft_str(tab);
	else if (*tab->format == 'd' || *tab->format == 'i' || *tab->format == 'u')
		ft_number(tab);

}

