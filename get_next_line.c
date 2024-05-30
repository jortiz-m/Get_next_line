/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/30 09:18:40 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_rest(char *buffer, int element)
{
	static char	*rest;
	int			start;
	int			counter;

	counter = 0;
	rest = malloc(((element - ft_len(buffer) + 1) * sizeof(char)));
	if (rest == NULL)
		return (NULL);
	start = buffer[ft_len(buffer) + 1];
	while ((start + counter) < element)
	{
		rest[counter] = buffer[start + counter];
		counter++;
	}
	return (rest);
}

char	*ft_createstr(char *temp, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*str;
	char			*buffer;
	int				element;
	int				i;
	static char		*rest;

	i = 0;
	if (rest != '\0')
		ft_strjoin(str, rest);
	while (buffer != '\n')
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		element = read(fd, buffer, BUFFER_SIZE);
		if (element < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_len(buffer) < element)
			rest = ft_rest(buffer, element);
		str = ft_createstr(buffer, ft_len(buffer));
	}
	free(buffer);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("caca.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
