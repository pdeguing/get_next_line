/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:16:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/09 11:38:08 by pdeguing         ###   ########.fr       */
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
//	ft_putendl("CALLING GET_NEXT_LINE IN MAIN");
	while (get_next_line(fd, &line))
	{
//		ft_putendl("GET_NEXT_LINE HAS BEEN CALLED");
//		if (line == NULL)
//			ft_putendl("LINE IS NULL IN MAIN");
//		ft_putendl("CURRENT LINE IS:");
		ft_putendl(line);
	}
//	ft_putendl("END OF MAIN");
	return (0);
}
