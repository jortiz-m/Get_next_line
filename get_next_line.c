/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/06/06 13:20:55 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	if (str == NULL)
		return(0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int ft_findstr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return(0);
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

char	*ft_lastline(buffer)
{
	char	*temp;
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	i++;
	
}

char	*ft_read(int fd)
{
	char	*buffer;
	int		element;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if	(!buffer)
		return (NULL);
	element = read(fd, buffer, BUFFER_SIZE);
	buffer[element] = '\0';
	if (element < BUFFER_SIZE && element >= 0)
	{
		ft_lastline(buffer);
	}
	return (buffer);
}

char	*ft_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = (ft_findstr(buffer, '\n') + 1);
	j = 0;
	while (buffer[j] != '\0')
		j++;
	while (j > i)
	{
		rest = malloc((j - i) * sizeof(char));
		if (!rest)
			return (NULL);
		j = 0;
		while (buffer[i + j] != '\0')
		{
			rest[j] = buffer[i + j];
			j++;
		}
		rest[j] = '\0';
		free(buffer);
	return (rest);	
	}
	
}

char	*ft_createnew(char *new, int i, char *newbuffer, char *buffer)
{
	int		j;

    j = 0;
	while (new[j] != '\0')
	{
		newbuffer[i + j] = new[j];
		j++;
	}
    newbuffer[i + j] = '\0';
	return (newbuffer);
}

char	*ft_join(char *buffer, char *new)
{
	char	*newbuffer = NULL;
	int		i;
	int		j;

	i = 0;
	if (new == 0)
		return(NULL);
	newbuffer = malloc((ft_strlen(buffer) + ft_strlen(new) + 1) * sizeof(char));
	if (!newbuffer)
		return (NULL);
	if (buffer)
		while (buffer[i] != '\0')
		{
			newbuffer[i] = buffer[i];
			i++;
		}
	newbuffer[ft_strlen(buffer)] = '\0';
	if (new)
		newbuffer = ft_createnew(new, i, newbuffer, buffer);
	free(buffer);
    free(new);
	return (newbuffer);
}
char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char		*line;
	char		*temp;

	buffer = ft_join(buffer, ft_read(fd));
	if (buffer != 0)
	{
		while (ft_check(buffer) == 0)
			buffer = ft_join(buffer, ft_read(fd));
		if (ft_check(buffer) == 1)
		{
			line = ft_createline(buffer);
			temp = ft_rest(buffer);
			buffer = temp;
			return (line);
		}
	}
	else
		return(buffer);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("caca.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}
