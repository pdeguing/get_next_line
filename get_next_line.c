/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/07 14:43:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
asdfasdfasd\nasdfasdfasd\n
while (str[i] != '\n')
	i++;
	*line = ft_strsub(str, 0, i);
	str = ft_strsub(str, i - 1, i);
while (ret = read(fd, buf, BUFF_SIZE)
buf[ret] = '\0';
str = ft_strjoin(str, buf);
	*/

int		get_next_line(const int fd, char **line)
{
	static char	**array;
	char		*buf;
	char		*tmp;
	int			ret;
	
	ft_putstr("get_next_line() start\n");
	if (!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (-1);
	ret = 0;
	if (array == NULL || array[1] == NULL)
	{
		if (!(ret = read(fd, buf, BUF_SIZE)))
			return (-1);
//		ft_putnbr(ret);
//		ft_putchar('\n');
		buf[ret] = '\0';
//		ft_putstr(buf);
		if (array == NULL)
			array = ft_strsplit(buf, '\n');
		else if (array[1] == NULL)
		{
			ft_putstr("else if\n");
			tmp = array[0];
//			ft_putstr(array[0]);
//			ft_putchar('\n');
			array = ft_strsplit(buf, '\n');
//			ft_putstr(array[0]);
//			ft_putchar('\n');
			if (array[0])
			{
//				ft_putstr("calling ft_strjoin()\n");
				array[0] = ft_strjoin(tmp, array[0]);
//				ft_putstr(array[0]);
//				ft_putchar('\n');
				ft_strdel(&tmp);
			}
		}
//		ft_putstr("recursion call\n");
		if (array)
		{
			ft_putstr(array[0]);
			ft_putchar('\n');
		}
		get_next_line(fd, line);
	}
//	ft_putstr(array[0]);
//	ft_putchar('\n');
//	if (array[1])
//		ft_putstr("oops\n");
	ft_putstr("duplicating into *line\n");
	*line = ft_strdup(array[0]);
	ft_putstr("duplicated into *line\n");
	ft_strdel(array);
	array++;
	ft_putstr("get_next_line() end\n");
	return (1);
}

// got to make it work when there is no \n within BUF_SIZE
