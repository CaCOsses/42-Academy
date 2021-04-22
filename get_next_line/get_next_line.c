/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:25:45 by ccubillo          #+#    #+#             */
/*   Updated: 2020/01/02 12:40:30 by camilo           ###   ########.fr       */
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

static int	ft_return(char **str, char **line, int i, int fd)
{
	char *aux;
	char *aux1;

	if (i < 0)
		return (-1);
	if (i == 0 && (str[fd] == NULL || str[fd][0] == 0))
		return (0);
	if ((aux = ft_strchr(str[fd], '\n')))
	{
		*aux = 0;
		*line = ft_strdup(str[fd]);
		printf("%s\n", *line);
		aux1 = ft_strdup(++aux);
		free(str[fd]);
		str[fd] = aux1;
		return (1);
	}
	else
	{
		*line = str[fd];
		str[fd] = 0;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int				i;
	int				BUFFER_SIZE = 9;
	static	char	*str[4096];
	char			buff[BUFFER_SIZE + 1];
	char			*temp;

	if (fd < 0 )
	{
		printf("%i\n", fd);
		return (-1);
	}
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{

		buff[i] = 0;
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ft_return(str, line, i, fd));
}

int main()
{
	int fd;
	char **line;

	fd = open("prueba.txt", O_RDONLY);
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	printf ("%i\n", get_next_line(fd,line));
	return(0);
}
