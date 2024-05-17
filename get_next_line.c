/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/17 12:12:38 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stash(char *buffer, char *str) //utiliamos el buffer para crear str
{
	int	i;

	i = 0;
	str = malloc((buffer) * sizeof(char));
	while (str[i] != '\0' && str[i] != '\n')
	{
		str[i] == buffer; //el buffer lo quiero en el str
		i++;
	}
	return (&str);
}

char *ft_reserve(char *str) //crea el str completo, en cada vuelta añade
{
	int	i;

	i = 0;
	while (str[i] == '\0') //colocarme en el último elemento del string
		i++;
	str[i] = *ft_stash
	i++;
	
}

void	ft_freestash(char *str) //liberar la memoria en cada vuelta
{
}

char	*get_next_line(int fd)
{
	char	*str; //string donde quiero almacenar lo que estoy leyendo
	size_t	bytesread; //número de elementos por vuelta leídos
	char	*buffer; //donde guardo mientras lo que se va leyendo

	bytesread = read(fd, buffer, BYTES_BUFFER);
	buffer = malloc((bytesread + 1) * sizeof(char));
	if (read == -1)
		return (-1);
	while (bytesread != 0) //lee y devuelve un número el read
	{
		while (bytesread > 0 && bytesread < 10)
		{
			ft_stash(&buffer, str); //para volcar la información
			ft_reverse(str); //crear el srting final que devolvemos
			bytesread--;
		}
	ft_freestash() //liberamos el buffer para la siguiente lectura
	}
	return (ft_reserve);
}
