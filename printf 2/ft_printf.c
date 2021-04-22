/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:07:08 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/13 20:23:39 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_start(t_tab *tab)
{
	while (*tab->format)
	{
		if(*tab->format == '%')
		{
			reinitialize(tab);
			tab->format++;
			ft_zerominus(tab);
			ft_width(tab);
			ft_precision(tab);
			ft_type(tab);
		}
		else
		{
			ft_putchar_fd(*tab->format, 1, tab);
		}
		tab->format++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_tab *tab;
	va_list	args;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	if (format)
	{
		va_start(args, format);
		tab->args = &args;
		ft_start(tab);
		va_end(args);
	}
	return(0);
}

/*int main()
{
	char *c = "aaaaaaaaa";
	ft_printf("    %.0s   ", "hello");
	return (0);
}*/
