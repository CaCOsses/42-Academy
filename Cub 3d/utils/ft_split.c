/

#include "utils.h"

t_str
	*ft_split(char const *org, char sep)
{
	int		i;
	int		start;
	t_str	*str;

	start = 0;
	i = 0;
	str = NULL;
	while (org[i])
	{
		if (org[i] == sep)
		{
			if (i - start > 0
				&& !str_add_back(&str, ft_substr(org, start, i - start)))
				return (PTR_CAST(str_clear(&str)));
			start = ++i;
		}
		else
			i++;
	}
	if (i - start > 0
		&& !str_add_back(&str, ft_substr(org, start, i - start)))
		return (PTR_CAST(str_clear(&str)));
	return (str);
}
