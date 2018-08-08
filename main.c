/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:16:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/07 18:07:20 by pdeguing         ###   ########.fr       */
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
//	get_next_line(fd, &line)
//	{
//		ft_putstr(line);
//		ft_putchar('\n');
//	}
//	ft_putstr("fsociety\n");
//
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	return (0);
}
