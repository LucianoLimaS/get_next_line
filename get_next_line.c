/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:07:29 by lucianosilv       #+#    #+#             */
/*   Updated: 2022/06/09 19:47:19 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*save(char *file)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(file) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (file[i])
		s[c++] = file[i++];
	s[c] = '\0';
	free(file);
	return (s);
}

char *get_line(char *file)
{
	int i;
	char *s;

	i = 0;
	if (!file[i])
		return (NULL);
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		s[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		s[i] = file[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char *read_file(int fd, char *file)
{
	char *ptr;
	int read_f;

	ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));

	if (!ptr)
		return (NULL);
	read_f = 1;
	while (!ft_strchr(file, '\n') && read_f != 0)
	{
		read_f = read(fd, ptr, BUFFER_SIZE);

		if (read_f == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[read_f] = '\0';
		file = ft_strjoin(file, ptr);
	}
	return (ptr);
}

char *get_next_line(int fd)
{
	static char *file;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	file = read_file(fd, file);
	line = get_line(file);
	file = save(file);
	return (line);
}
