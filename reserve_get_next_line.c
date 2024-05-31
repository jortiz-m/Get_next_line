#include "get_next_line.h"

void	ft_free(char *str)
{
	free(str);
	str = NULL;
}
int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_search(char *reserve, char c)
{
	int	i;

	i = 0;
	while (reserve[i])
	{
		if (reserve[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*line;

	line = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	i = 0;
	j = 0;
	if (s1 == NULL|| s2 == NULL)
	{
		ft_free(line);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		line[i] = s1[i];
		i++;
	}
	while(s2[i] != '\0')
	{
		line[i] = s2[i + j];
		j++;
	}
	return (line);
}



char	*ft_cleanreserve(char *reserve)
{
	int	i;
	int	j;

	i = 0;
	while (reserve[i] != '\n')
		i++;
	j = 0;
	while (reserve[i] != '\0')
	{
		reserve[j] = reserve[i + j];
		j++;
	}
	return (reserve);
}
char	*ft_createline(char *reserve)
{
	char	*line;
	int		i;

	i = 0;	
	if(reserve[i] == '\n')
	{
		while (reserve[i] != '\n')
		{
			reserve[i] = line[i];
			i++;
		}
		return (line);
	}
	else
		return(reserve);
}

char	*get_next_line(int fd)
{
	int			bytesread;
	static char	*reserve;
	int			i;
	char		*buffer;
	
	i = 0;
	reserve = malloc(BUFFER_SIZE * sizeof(char));
	if (!reserve)
		return (NULL);
	bytesread = read(fd, reserve, BUFFER_SIZE);
	while (ft_search(reserve, '\n') == 0 || reserve[i] != '\0')

	{
			read(fd, buffer, BUFFER_SIZE);
			reserve = ft_join(reserve, buffer);
			i++;
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
