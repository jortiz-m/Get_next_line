/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/31 15:48:16 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_check(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*ft_createline(char *buffer)
{
	int		i;
	char	*line;

	
	i = 0;
	while (buffer[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*ft_read(int fd)
{
	char	*buffer;
	int		element;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if	(!buffer)
		return (NULL);
	element = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

char	*ft_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	j = 0;
	while (buffer[i] != '\0')
		j++;
	rest = malloc((j + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
	{
		rest[j] = buffer[i + j];
		j++;
	}
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

char	*ft_join(char *buffer, char *new)
{
	char	*newbuffer;
	int		i;
	int		j;

	i = 0;
	newbuffer = malloc(ft_strlen(buffer) + ft_strlen(new) * sizeof(char));
	while (buffer[i])
	{
		newbuffer[i] = buffer[i];
		i++;
	}
	j = 0;
	while (new)
	{
		newbuffer[i + j] = new[j];
		j++;
	}
	free(buffer);
	free(new);
	return (newbuffer);
}
char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;

	buffer = ft_read(fd);
	while (ft_check(buffer) == 0)
		buffer = ft_join(buffer, ft_read(fd));
		if (ft_null(buffer) == 1)
			
	if (ft_check(buffer) == 1)
	{
		line = ft_createline(buffer);
		buffer = ft_rest(buffer);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("caca.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
