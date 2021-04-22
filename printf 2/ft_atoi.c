/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:34:15 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/08 20:17:30 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32 || str[i] == '\f' || str[i] == '\r' || str[i] == '\n'
				|| str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (sign * res);
}
