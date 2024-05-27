/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/27 13:38:31 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0' || str[c] != '\n')
		c++;
	return (c);
}

char	*ft_rest(char *buffer, int element)
{
	char	*rest;
	int		start;

	rest = malloc((element - ft_len(buffer) * sizeof(char)));
	if (rest == NULL)
		return (NULL);
	start = buffer[ft_len(buffer) + 2];
	while (start < element)
	{
		rest[start] = buffer[start];
		start++;
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
	while (i > len)
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	int			element;
	int			i;
	char		*rest;

	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	element = read(fd, buffer, BUFFER_SIZE);
	if (element < 0)
		return (NULL);
	if (ft_len(buffer) < element)
		rest = ft_rest(buffer, element);
		strjoin(str rest)
	str = ft_createstr(buffer, element);
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
