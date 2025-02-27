/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:07 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/06/12 10:23:46 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc (((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	j = 0;
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
	free (s1);
	return (str);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)(buffer + ft_strlen(buffer)));
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)(buffer + i));
		i++;
	}
	return (NULL);
}

void	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	str = (malloc(count * size));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
