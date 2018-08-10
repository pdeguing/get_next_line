/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:16:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/10 07:39:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_putendl(line);
	while (1);
	return (0);
}
