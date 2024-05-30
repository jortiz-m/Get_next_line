/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/30 13:51:16 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search(char *reserve, char c)
{
	int	i;

	i = 0;
	while (reserve[i] != '\n' || reserve[i])
		if (reserve[i] == '\n')
			return (1);
		i++;
	return(0);
}

char	*ft_join(char *s1, char *s2)
{
}

void	ft_free(char *str)
{
}

char	ft_cleanreserve(char *reserve)
{
}
char	*ft_createline(char *reserve)
{
	char	*line;

	if(reserve == '\n')
	{
		reserve[i] == line[i]
		i++;
	}
	else
		
	
	return(line);
}

char	*get_next_line(int fd)
{
	int			bytesread;
	static char	*reserve = NULL;
	int			i;
	char		*buffer;
	
	i = 0;
	while (ft_search(reserve, '\n') == 0 || reserve[i] != '\0')
	{
			read(fd, buffer, BUFFER_SIZE);
			reserve = ft_join(reserve, buffer);
	}
	ft_createline(reserve);
	ft_cleanreserve(reserve);

	return (buffer);
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
