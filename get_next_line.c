/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/23 11:27:05 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_stash(fd) //lee caracter y lo devuelve
{
	char 	*temp;
	int		i;

	i = 0;
	temp = malloc(2 * sizeof(char));
	read(fd, &temp, 1);
	return (&temp);
}*/

char *ft_reserve(char c) //crea el str completo, en cada vuelta añade
{
	char	*str; //mi str final
	int		i;

	str = malloc()
	i = 0;
	while (str[i] == '\0') //colocarme en el último elemento del string
		i++;
	str[i] = temp;
	i++;	
}

void	ft_freestash(char *str) //liberar la memoria en cada vuelta
{
}

char	*get_next_line(int fd)
{
	char	*str; //string final
	char	*buffer;
	int		element;
	int		i;

	i = 0;
	element = read(fd, buffer, BUFFER_SIZE)
	if (element != 0) //lee y devuelve un número el read
	{
		while (buffer[i] != '\0')
		{
			ft_reserve(buffer[i]); //crear el srting final que devolvemos
			i++;
		}
	ft_freestash() //liberamos el buffer para la siguiente lectura
	}
	else
		return (-1);
	return (ft_reserve);
}
