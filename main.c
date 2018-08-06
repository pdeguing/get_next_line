/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:16:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/06 12:31:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	**line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	if(!(line = (char **)malloc(sizeof(char *) * 11)))
		return (-1);
	line[10] = NULL;
	i = 0;
	ft_putstr("fsociety\n");
	get_next_line(fd, line);
	ft_putstr("fsociety\n");
	ft_putstr(line[i]);
	ft_putchar('\n');
	return (0);
}
