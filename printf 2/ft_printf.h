/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:27:13 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/14 19:31:54 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_tab
{
	const char	*format;
	int			len;
	size_t			precision;
	int			menos;
	int			zero;
	int			point;
	int			width;
	int			dot;
	int			var_char_int;
	char		*var_str;
	va_list		*args;

}				t_tab;

void	ft_putnbr_fd(int n, int fd, t_tab *tab);
void	ft_putchar_fd(char c, int fd, t_tab *tab);
t_tab	*initialize(t_tab *tab);
void	ft_zerominus(t_tab *tab);
void	ft_width(t_tab *tab);
void	ft_precision(t_tab *tab);
void	ft_type(t_tab *tab);
void	ft_char(t_tab *tab);
void	ft_printminus_char(t_tab *tab);
void	ft_str(t_tab *tab);
void	ft_printminus_str(t_tab *tab);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_printpreci_str(t_tab *tab);
void	ft_printprecimin_str(t_tab *tab);
void	ft_print_str(t_tab *tab);
void	reinitialize(t_tab *tab);
void	ft_number(t_tab *tab);
#endif