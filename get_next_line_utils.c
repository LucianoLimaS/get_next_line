/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:18:18 by lucianosilv       #+#    #+#             */
/*   Updated: 2022/06/10 00:07:14 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	int i;
	int j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[j] = s2[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char *ft_strchr(char *str, int c)
{
	int i;
	int len;

	i = 0;
	if (c == '\0')
	{
		len = ft_strlen(str);
		return ((char *)(str + len));
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}