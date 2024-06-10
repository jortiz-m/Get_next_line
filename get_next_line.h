/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:52:27 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/06/10 11:49:43 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 4
#endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *rest);
char	*ft_createline(char *buffer);
char	*ft_createrest(char *buffer);
char	*ft_free(char *buffer, char *buf);
void	*ft_calloc(int count, int size);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int chr);
char	*ft_strjoin(char *s1, char *s2);

#endif