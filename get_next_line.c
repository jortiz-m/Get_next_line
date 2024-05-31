/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/31 09:16:35 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	char	lends3;

	lends3 = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc ((lends3 + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
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
	char		*rest;
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

char	*ft_createline(char *buffer, size_t len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_readbuffer(char *str)
{
	int			element;
	static char	*buffer;
	int			i;
	char		*line;

	i = 0;
	
	buffer = malloc(1 * sizeof(char));
	if (buffer == NULL)
			free(buffer);
			return (NULL);
	element = read(fd, buffer, BUFFER_SIZE);
	while (element > 0)
		while (buffer[i] != '\n' || buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
				return (line = ft_createline(buffer, ft_len(buffer)));
			i++;		
		}
		read()
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*buffer;
	int				element;
	int				i;
	char			*rest;

	i = 0;
	if (rest != '\0') //si hay resto, une el resto con el actual
		str = ft_strjoin(rest, str);
	while (str[i] != '\n' || str[i] != '\0') //comprobar si he llegado al final de la línea
	{	
		ft_readbuffer(str);
		i++;
	}
	if (ft_len(buffer) < element) //si lo que tenemos nos sobra, crea rest
		rest = ft_rest(buffer, element);
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
