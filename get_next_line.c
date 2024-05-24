/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/24 10:07:57 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*ft_stash(buffer[i]) //lee caracter y lo almacena temporalmente
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(BUFFER_SIZE * sizeof(char));
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	return (&temp);
}

char	*ft_reserve(ft_stash) //crea el str completo, en cada vuelta añade
{
	char	*str; //mi str final
	int		i;

	str = malloc(); //que memoria le doy?? en cada vuelta es mayor
	i = 0;
	while (str[i] == '\0') //colocarme en el último elemento del string
		i++;
	while(temp[i] '\0')
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}

void	ft_freestash(char *str)
{
	free(temp);
}
*/
char	*get_next_line(int fd)
{
	char	*str;
	char	*buffer;
	int		element;
	int		i;

	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	element = read(fd, buffer, BUFFER_SIZE);
	if(element != 0)
	{
		while (buffer[i] != '\0')
		{
			ft_stash(&buffer[i]);
			i++;
		}
	}
	else
		return(-1);
	return(buffer);
}
int main()
{
	int fd;
	char *line;

	fd = open("caca.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
