/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/24 12:45:25 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reserve(char *buffer)
{
	int		count;
	char	*str;

	count = 0;
	while ((buffer[count] != '\n' || buffer[count] != '\0') \
	&& count < BUFFER_SIZE)
		count++;
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (buffer[count] != '\0')
	{
		str[count] = buffer[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*buffer;
	int		element;
	int		i;

	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	element = read(fd, buffer, BUFFER_SIZE);
	if (element < 0)
		return (NULL);
	while (i < BUFFER_SIZE)
		i++;
	buffer[i] = '\0';
	str = ft_reserve(buffer);
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
