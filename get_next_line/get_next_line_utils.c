/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:50:42 by ccubillo          #+#    #+#             */
/*   Updated: 2019/12/14 21:07:57 by ccubillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strcpy(char *dest, const char *src)
{
	int coun;

	coun = 0;
	while (src[coun] != '\0')
	{
		dest[coun] = src[coun];
		coun++;
	}
	dest[coun] = '\0';
	return (dest);
}

char			*ft_strcat(char *dest, const char *src)
{
	int count1;
	int count2;

	count1 = 0;
	while (dest[count1] != '\0')
		count1++;
	count2 = 0;
	while (src[count2] != '\0')
	{
		dest[count1 + count2] = src[count2];
		count2++;
	}
	dest[count1 + count2] = '\0';
	return (dest);
}

char			*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

char			*ft_strjoin(const char *s1, char const *s2)
{
	char	*result;
	int		c;
	int		c1;
	size_t	size;

	if (s1 && s2)
	{
		c = 0;
		while (s1[c] != 0)
			c++;
		c1 = 0;
		while (s2[c1] != 0)
			c1++;
		size = (size_t)(c + c1);
		if (!(result = malloc(sizeof(char) * (size + 1))))
			return (0);
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
		return (result);
	}
	return (0);
}
