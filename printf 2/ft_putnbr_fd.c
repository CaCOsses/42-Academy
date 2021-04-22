/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:17:56 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:27:22 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, t_tab *tab)
{
	unsigned int aux;

	if (n < 0)
	{
		ft_putchar_fd('-', fd, tab);
		n = n * -1;
	}
	aux = n;
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd, tab);
	ft_putchar_fd(aux % 10 + '0', fd, tab);
}
