/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:07 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/06/10 13:25:40 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	char	lends3;

	lends3 = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc ((lends3 + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[(i + j)] = '\0';
	return (str);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_strchr(char *str, int chr)
{
	int	i;

	i = 0;
	if ((char)chr == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

void	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	str = (malloc(count * size));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
