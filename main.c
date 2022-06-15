/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:08:19 by lucianosilv       #+#    #+#             */
/*   Updated: 2022/06/15 11:46:11 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("teste.txt", O_RDWR | O_CREAT);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	return (0);
}
