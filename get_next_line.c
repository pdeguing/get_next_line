/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/06 12:31:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int		i;
	int				j;
	int				ret;
	char			*buf;
	char			*tmp;
	int				new_line;
	
	if (!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (-1);
	new_line = 0;
	while (new_line == 0)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ret == 0)
			return (0);
		buf[ret] = '\0';
		j = 0;
		while (buf[j] && new_line == 0)
		{
			if(buf[j] == '\n')
			{
				tmp = ft_strncpy(tmp, buf, j);
				ft_strclr(&buf[j]);	
				new_line = 1;
			}
			j++;
		}
		i = 0;
		ft_putstr(buf);
		ft_putchar('\n');
		line[i] = buf;
		ft_putstr(line[i]);
		ft_putchar('\n');
		ft_putchar('\n');
//		if (!new_line)
//		{
//			get_next_line(fd, line + 1);
//		}
	}
	return (1);
}
