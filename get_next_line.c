/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:49:22 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/07 18:07:21 by pdeguing         ###   ########.fr       */
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

char	*get_all_file(const int fd)
{
	char	*buf;
	char	*tmp1;
	char	*tmp2;
	int		ret;

	if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (NULL);
	if (read(fd, buf, 0) == -1)
		return (NULL);
	tmp1 = ft_strnew(1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp2 = tmp1;;
		tmp1 = ft_strjoin(tmp2, buf);
		ft_strdel(&tmp2);
	}
	return (tmp1);
}

int		get_next_line(const int fd, char **line)
{
	static int		i = 0;
	static char		**array;
	char			*tmp;
//	char			*buf;
//	int				ret;

	if (!array)
	{
//		if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
//			return (-1);
//		if (read(fd, buf, 0) == -1)
//			return (-1);
//		tmp = ft_strnew(1);
//		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
//		{
//			buf[ret] = '\0';
//			tmp = ft_strjoin(tmp, buf);
//		}
		if (!(tmp = get_all_file(fd)))
			return (-1);
		array = ft_strsplit(tmp, '\n');
		ft_strdel(&tmp);
	}
	if (array[i])
	{
		*line = array[i];
		if (i > 0)
			ft_strdel(array);
		i++;
		return (1);
	}
	return (0);
}
