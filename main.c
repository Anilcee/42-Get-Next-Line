/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancengiz <ancengiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:08:27 by ancengiz          #+#    #+#             */
/*   Updated: 2024/12/15 21:28:19 by ancengiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;

	fd = open("texts/example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 0;
	while (i < 12)
	{
		next_line = get_next_line(fd);
		printf("satir %d : %s", i + 1, next_line);
		free(next_line);
		i++;
	}
	close(fd);
	return (0);
}
